// String_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string_list.h"
#include <string>
#include <sstream>

using namespace std;

int main() {
	String_List test = String_List();
	
	test.push_back("every royal cat felt with a green hill");
	test.push_back("a hungry man smiled from a tough path");
	test.push_back("no yummy girl ran on every royal lake");

	cout << test.to_string();
	cout << test.get_current() << endl <<endl;

	test.advance_current();
	cout << test.to_string();
	cout << test.get_current() << endl << endl;

	test.advance_current();
	cout << test.to_string();
	cout << test.get_current() << endl << endl;

	test.advance_current();
	cout << test.to_string();
	cout << test.get_current() << endl << endl;

	test.advance_current();
	cout << test.to_string();
	cout << test.get_current() << endl << endl;

	test.advance_current();
	cout << test.to_string();
	cout << test.get_current() << endl << endl;


	test.insert_at_current("test test");

	cout << test.get_current() << endl << endl;

	cout << test.to_string();
	cout << test.get_current() << endl << endl;

	test.push_back("the glowing girl cried over the cool fox");
	test.push_back("the glowing wise guy cried on the high man");
	test.push_back("a cool tree ate in every yummy wise gal");
	test.push_back("a high lake cried in no yummy squirrel");
	test.push_back("the green boy tiptoed without the green girl");
	test.push_back("a crying woman leaned in a red path");
	test.push_back("a cool rainbow learned without a royal lake");
	test.push_back("a glowing woman laughed on a hot tyke");
	test.push_back("no tough woman kissed at a royal man");
	test.push_back("a cool brat sat with no green hat");
	test.push_back("a green squirrel sat on the tough fox");
	test.push_back("every handsome tyke smiled from the tough chair");
	test.push_back("no yummy path ran at no funny man");
	test.push_back("the high chair sat from every blue boy");
	test.push_back("no red wise gal ate from the red tyke");
	test.push_back("a glowing wise gal ran in the hot fox");
	test.push_back("every hungry hat felt on the hungry hat");
	test.push_back("no handsome tree ate over a rad cat");
	test.push_back("a funny wise guy studied with the royal mountain");
	test.push_back("every hot tree smiled on the crying hill");
	test.push_back("every tough cat cried at every handsome path");
	test.push_back("no funny boy ate under the hot boy");
	test.push_back("every dapper tyke hit at the yummy hill");
	test.push_back("a cool hat loved on no red brat");
	test.push_back("no funny hill hit without no tough path");
	test.push_back("a funny cat hit on a royal chair");
	test.push_back("every laughing woman leaned from every red lake");
	test.push_back("no funny bush learned under every glowing hill");
	test.push_back("no rad chair studied under every blue woman");
	test.push_back("every blue mat learned at the high hat");
	test.push_back("every glowing wise guy kissed with the handsome tyke");
	test.push_back("the yummy tree sat on every glowing hill");
	test.push_back("no laughing mountain studied with no glowing mat");
	test.push_back("the crying wise gal cried under the hungry tyke");
	test.push_back("the cool bush ran with a glowing hat");
	test.push_back("a blue wise guy walked under the rad rainbow");
	test.push_back("every hungry mountain learned on every hot boy");
	test.push_back("the red mountain laughed on every royal cat");
	test.push_back("every glowing path swam on no green lake");
	test.push_back("no funny squirrel learned at every crying lake");
	test.push_back("no blue mat learned without no hot lake");
	test.push_back("no handsome cat leaned at the rad lake");
	test.push_back("no high wise guy loved without every rad hill");
	test.push_back("no glowing cat leaned under the laughing mat");
	test.push_back("no red lake cried under every funny tree");
	test.push_back("a rad mat ran in the green girl");
	test.push_back("no handsome squirrel loved from a tough woman");
	test.push_back("no dapper path walked over the royal mountain");
	test.push_back("every cool bush ate in no glowing bush");
	test.push_back("a rad woman learned in every cool mountain");
	test.push_back("the high hat sat in a dapper mat");
	test.push_back("a tough tree hit over every red boy");
	test.push_back("every funny rainbow laughed over the laughing mat");
	test.push_back("every handsome man sat in every green boy");
	test.push_back("a red chair walked from every red wise gal");
	test.push_back("every yummy chair leaned in a hungry chair");
	test.push_back("the blue girl swam in a hungry boy");
	test.push_back("every dapper lake ran under a glowing path");
	test.push_back("a cool lake tiptoed on a glowing bush");
	test.push_back("every crying mat hit on the dapper lake");
	test.push_back("the hot wise guy loved on a green mountain");
	test.push_back("no laughing wise gal loved on no tough cat");
	test.push_back("the royal brat walked without no rad brat");
	test.push_back("no handsome lake tiptoed at the red wise guy");
	test.push_back("the crying fox tiptoed on every green wise guy");
	test.push_back("every yummy chair cried from the rad fox");
	test.push_back("the funny squirrel laughed at the glowing wise guy");
	test.push_back("a laughing wise gal sat at every crying squirrel");
	test.push_back("every yummy woman swam at no crying mat");
	test.push_back("a hungry rainbow leaned at the dapper fox");
	test.push_back("a red girl studied at no royal mat");
	test.push_back("every royal tree laughed over a handsome man");
	test.push_back("every glowing wise gal walked with the hungry lake");
	test.push_back("the hungry wise gal leaned over a royal girl");
	test.push_back("no high hat smiled on every tough squirrel");
	test.push_back("the cool wise gal leaned on no funny brat [marked PREV]");
	test.push_back("the glowing path swam over the tough hat");
	test.push_back("a yummy chair ate with a tough woman");
	test.push_back("every tough mountain tiptoed over a tough wise gal");
	test.push_back("no green boy smiled over no dapper wise gal");
	test.push_back("every hungry squirrel loved in every funny woman");
	test.push_back("a hot squirrel learned without no royal hat");
	test.push_back("no cool squirrel laughed with no yummy brat");
	test.push_back("no funny wise guy hit without the high girl");
	test.push_back("the blue lake ran at every high lake");
	test.push_back("no blue wise gal hit under no tough hill");
	test.push_back("every dapper path walked on the crying tree");
	test.push_back("every laughing path learned without every blue rainbow");
	test.push_back("no blue mountain learned without the high wise guy");
	test.push_back("a rad boy studied with every rad man");
	test.push_back("no hot chair hit over every tough rainbow");
	test.push_back("a red chair walked with the funny mat");
	test.push_back("no hungry lake laughed without every high tyke");
	test.push_back("a cool brat loved in a hot hat");
	test.push_back("no hungry hat kissed with the red lake");
	test.push_back("every hot mountain leaned over the royal rainbow");
	test.push_back("a red squirrel loved over every high chair");
	test.push_back("a hungry path sat with a laughing tree");
	test.push_back("the handsome mountain kissed at every yummy wise guy");
	test.push_back("every rad girl learned over every red lake");
	test.push_back("a royal mat kissed under every crying mountain");
	test.push_back("no crying tyke walked under no royal hat");
	test.push_back("no laughing hat laughed on every rad wise gal");
	test.push_back("the royal girl learned at no blue hat");
	test.push_back("no hungry wise gal smiled without every hot man");
	test.push_back("a hot hat ate with no yummy brat");
	test.push_back("the cool tree walked over a cool hill");
	test.push_back("every handsome girl swam in no dapper cat");
	test.push_back("the cool hill smiled under a crying hat");
	test.push_back("no tough hat tiptoed at a glowing path");
	test.push_back("no hot girl ate over every royal wise guy");
	test.push_back("no funny tyke kissed under the hungry mat");
	test.push_back("no royal fox hit on every funny hill");
	test.push_back("every glowing bush leaned on the red cat");
	test.push_back("a blue brat tiptoed from every crying lake");
	test.push_back("no hungry wise guy studied with a laughing squirrel");
	test.push_back("the tough woman leaned at every glowing cat");
	test.push_back("a green lake loved over no laughing squirrel");
	test.push_back("the red chair smiled with the funny path");
	test.push_back("every royal man laughed under no glowing hat");
	test.push_back("the yummy fox laughed at the dapper tree");
	test.push_back("a red hat hit over a dapper wise guy");
	test.push_back("no hot tyke kissed without the hungry cat");
	test.push_back("a rad lake kissed in every blue woman");
	test.push_back("a high girl studied on every high fox");
	test.push_back("a crying squirrel cried at no crying brat");
	test.push_back("a cool hat walked from no high mat");
	test.push_back("every blue man hit without no high rainbow");

	for (int i = 1; i <= 80; i++) {
		test.advance_current();
	}

	cout << test.to_string();

	test.insert_at_current("test");
	cout << test.to_string();

	test.push_front("front");
	cout << test.to_string();

	test.remove_at_current();
	cout << test.to_string();

}