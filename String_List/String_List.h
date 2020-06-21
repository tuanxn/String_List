// String_List.h
//
#ifndef String_List_h
#define String_List_h
#include <iostream>
#include <sstream>
// Important implementation note: With the exception of to_string(),
// and clear(), all list methods below should operate in a constant amount
// of time regardless of the size of the String_List instance.
//
// The semantics of _prev_to_current is such that it always points to the
// node *BEFORE* the current one. This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
//
// I've included some method header comments below where there's likely to
// be confusion.
//
class String_List {
private:
	struct Node {
		std::string data;
		Node* next;
		Node(std::string s = "") : data(s), next(nullptr) {}
	};
	Node* _head, * _tail, * _prev_to_current;
	size_t _size;
public:
	String_List() {
		struct Node* temp = new Node("_SENTINEL_");
		_head = temp;
		_tail = temp;
		_prev_to_current = _head;
		_size = 0;
	}
	~String_List() {
		delete _head;
		//delete _tail;
		//delete _prev_to_current;       
	}
	String_List* insert_at_current(std::string s) {
		struct Node* newNode = new Node;
		newNode->data = s;
		newNode->next = _prev_to_current->next;
		
		if (_prev_to_current->next == nullptr) {
			_prev_to_current->next = newNode;
			_tail = _prev_to_current->next;
		}
		else {
			_prev_to_current->next = newNode;
		}
		_size++;

		return this;
	}
	String_List* push_back(std::string s) {         
		Node* original = _prev_to_current;
		_prev_to_current = _tail;
		insert_at_current(s);
		_tail = _prev_to_current->next;
		_prev_to_current = original;
		return this;
	}
	String_List* push_front(std::string s) {
		Node* original = _prev_to_current;
		_prev_to_current = _head;
		insert_at_current(s);
		_prev_to_current = original;

		return this;
	}
	String_List* advance_current() {
		if (_prev_to_current->next == nullptr) {
			return nullptr;
		}
		_prev_to_current = _prev_to_current->next;
		return this;
	}
	std::string get_current() const {
		if (_prev_to_current->next != nullptr) {
			return _prev_to_current->next->data;
		}
		return "_SENTINEL_";
	}
	String_List* remove_at_current() {
		struct Node* removedNode = _prev_to_current->next;
		_prev_to_current->next = removedNode->next;
		_size--;
		return this;
	}
	size_t get_size() const {
		return _size;
	}
	String_List* rewind() {
		_prev_to_current = _head;
		return this;
	}
	void clear() {
		size_t total = _size;
		_prev_to_current = _head;
		for (size_t i = 0; i < total; i++) {
			if (!(_prev_to_current->next == nullptr)) {
				//_prev_to_current = _prev_to_current->next;
				remove_at_current();
			}
		}
		_prev_to_current = _head;
		_tail = _head;
		_head->next = nullptr;
	}
	// Find a specific item. Does NOT change cursor.
	//
	// The following returns a reference to the target string if found. But what will
	// you do if you didn't find the requested string? Using sentinel markers is
	// one way to handle that situation. Usually there's only one copy of the
	// sentinel that's global. We will use a local one so it's cleaner with a
	// little more risk (what's the risk?)
	//
	std::string& find_item(std::string s) const {
		static std::string SENTINEL = "_SENTINEL_";
		Node* temp = _head;

		for (size_t i = 0; i < _size; i++) {
			if (temp->next == nullptr) {
				return SENTINEL;
			}
			if (temp->next->data == s) { 
				return temp->next->data;
			}else {
				temp = temp->next;
			}
		}
		return SENTINEL;
	}
	// Print up to max_lines lines starting at _prev_to_current->next. If the caller
	// wants to print from the beginning of the list, they should rewind() it first.
	//


	std::string to_string() const {
		std::string output = "# String_List: " + std::to_string(_size);
		output += " entries total. Starting at head:\n";
		Node* temp = _head;
		do {     

			output += temp->data;

			if (temp == _prev_to_current) {
				output += " [marked PREV]";
			}

			output += "\n";

			temp = temp->next;

		} while (temp != NULL);
		output += "\n";
		return output;
	}


	//std::string to_string() const {
	//	static int unsigned MAX_LINES = 25;
	//	std::string output = "# String_List - " + std::to_string(_size);
	//	output += " entries total. Starting at cursor:\n";
	//	Node* temp = _head->next; 
	//	if (_size != 0) {
	//		for (size_t i = 0; i < MAX_LINES; i++) {
	//			
	//			output += temp->data + "\n";
	//			if (temp->next == nullptr) {
	//				break;
	//			}
	//			temp = temp->next;
	//		}
	//		if (_size > MAX_LINES) {
	//			output += "...\n";
	//		}
	//	}
	//	output += "\n";
	//	return output;
	//}

	friend class Tests; // Don't remove this line
};
#endif /* String_List_h */