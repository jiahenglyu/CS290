/******************************************************
 * Program: wizard_catalog.cpp
 * Author: Jiaheng Lyu
 * Date: 07/06/2019
 * Description:The program is a spellbook catalog system. After the user logins successfully, the user can sort the information about the spell books and spells in three different ways,sorting the spell books by page number, sorting the spells by effect, or sorting the spell books by the average success rate. After that, the program would print the information by the way the user choose on the screen. If the user is a student, she or he would not see the books that have the spell can cause death(death and poison).
 * Input:the file name, ID, password, the ways the user want to show the information
 * Output:the information about the spell books and spells
********************************************************/

#include <iostream>
#include <cstring>

#include "catalog.h"

using namespace std;

/***************************************************
 * Funtion: main function
 * Description: the main function for the whole program, and it is used to call other functions
 * Parameters: the name of two file
 * Pre-Conditions: the user runs the program
 * Post_Conditions: Program end
***************************************************/

int main(int argc,char *argv[]){
	int peop,boo,adult;
	if ((argc==3)&&(name_righ(argv,1,peop)==true)&&(name_righ(argv,2,boo)==true)){//check whether the two files can be opened or not
		struct wizard *people=create_wizard(peop);//create the two array which are used to store the information about wizards and spell books
		struct spellbook *book=create_spellbooks(boo);
		open_wizard(people,argv,peop);//input the information about wizards and spell books to array
		get_book(argv,book,boo);
		do{
			login(people,peop,adult);
			ways(book,boo,adult);
		}while(again()==true);//if the user want to sort the information in different way
		delete_info(&people,peop,&book,boo);
	}
	return 0;
}
