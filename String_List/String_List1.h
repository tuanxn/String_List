// String_List.h
//
#ifndef String_List_h
#define String_List_h
#include <iostream>
#include <sstream>

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

	// TODO - You will need to fill in the inline implementations of
	// all the public methods below.
	String_List() {
		_head = new Node;
		_tail = new Node;
		_prev_to_current = new Node;
		_head->data = "_SENTINEL_";
		_head->next = _tail;
		_tail->data = "_SENTINEL";
		_tail->next = nullptr;
		_prev_to_current->data = "_SENTINEL";
		_prev_to_current->next = _head;
	}
	~String_List() {
		delete _head;
		delete _tail;
		delete _prev_to_current;
	}
	size_t get_size() const {
		int count = 0;
		Node* current = _head;
		while (current != NULL) {
			count++;
			current = current->next;
		}
		return count;
	}

	void clear() {
		for (size_t i = 0; i < get_size(); i++) {
			if (!(_prev_to_current->next == nullptr)) {
				_prev_to_current = _prev_to_current->next;
				remove_at_current();
			}
		}
		_prev_to_current = _head;
		_tail = _head;
		_head->next = nullptr;
	}

	String_List* rewind() {
		_prev_to_current->next = _head;
		return this;
	}

	String_List* insert_at_current(std::string s) {

		struct Node* newNode = new Node;
		newNode->data = s;
		newNode->next = _prev_to_current->next;
		_prev_to_current->next = newNode;
		return this;
		
	}
	String_List* remove_at_current() {
		struct Node* removedNode = _prev_to_current->next;
		_prev_to_current->next = removedNode->next;
		return this;
	}

	String_List* push_front(std::string s) {
		
		_prev_to_current = _head;
		insert_at_current(s);
		_head->next = _prev_to_current;
		return this;

	}
	String_List* push_back(std::string s) {

		struct Node* original = _prev_to_current;
		_prev_to_current = _tail;
		insert_at_current(s);
		_prev_to_current = original;
		return this;

	}

	// Remember that _prev_to_current can never be null because it's at
	// least equal to the list header. The current element visible to the user
	// is always the element AFTER _prev_to_current. So when you're advancing,
	// you can't advance further than the tail node (again a real non-null node).
	//
	String_List* advance_current() {
		if (_prev_to_current->next == nullptr) {
			return nullptr;
		}
		_prev_to_current = _prev_to_current->next;
	}
	// This method is only a few lines, but please make sure you understand it
	// fully. Ask in the forums if any of it is unclear.
	//
	// The current item is the data element of whichever node is equal to
	// _prev_to_current->next.
	//
	// Ideally, we would throw an exception if _prev_to_current->next == null, which
	// should not happen, really. But since we haven't covered exceptions yet, we will
	// hack a return to a static sentinel, with the understanding that the caller
	// won't mess with the sentinel (see the spec).
	std::string get_current() const {
		if (_prev_to_current != NULL) {
			return _prev_to_current->data;
		}
		return "_SENTINEL_";
	}
	// Find a specific item. Does NOT change cursor.
	//
	// The following returns a reference to the target string if found. But what will
	// you do if you didn't find the requested string? Using sentinel markers is
	// one way to handle that situation. Usually there's only one copy of the
	// sentinel that's global. We will use a local one so it's cleaner with a
	// little more risk (what's the risk?)
	std::string& find_item(std::string s) const {
		static std::string SENTINEL = "_SENTINEL_";
		Node* temp = _prev_to_current;

		for (size_t i = 0; i < get_size(); i++) {
			if (temp->data == s) {
				return temp->data;
			}
			if (!(temp->next == nullptr)) {
				temp = temp->next;
			}
			else {
				return SENTINEL;
			}
		}
	}
	// Print up to max_lines lines starting at _prev_to_current->next. If the caller
	// wants to print from the beginning of the list, they should rewind() it first.
	// max_lines can be a local constant = 25;
	std::string to_string() const {
		static int unsigned MAX_LINES = 25;
		std::string output = "# String_List - " + get_size();
		output +=" entries total. Starting at cursor:\n";
		Node* temp = _head;
		for (size_t i = 0; i < MAX_LINES; i++) {
			if (temp->next != nullptr) {
				output += temp->data + "\n";
				temp = temp->next;
			}
		}
		if (get_size() > MAX_LINES) {
			output += "...\n";
		}
		output += "\n";
		return output;
	}
};
