#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>

#include "catalog.h"

using namespace std;

/***********************************************************************
 * Function: name_righ 
 * Description: check the two files can be opened or not
 * Parameters: the name of files,the size of dynamic array,the serial number of files
 * Pre-Conditions: call the function to check the name
 * Post-Conditions: finishing check the file
***********************************************************************/

bool name_righ(char **argv,int b,int &c){
	ifstream f1;
	string a=argv[b];
	f1.open(a.c_str(),ifstream::in);//open the file
	if (f1.is_open()){
		string number;
		getline(f1,number);
		c=atoi(number.c_str());//get the size of dynamic array
		f1.close();
		return true;
	}
	else{
		cout << "The file No. " << b << " cannot be opened!!\n";//tell user which file can not be opened
		return false;
	}		
}

/***********************************************************************
 * Function: wizard* create_wizard
 * Description: create a dynamic array to store wizard
 * Parameters: the size of dynamic array
 * Pre-Conditions: call the function to create the array
 * Post-Conditions: finish creating the array
***********************************************************************/

struct wizard* create_wizard(int a){
	struct wizard *people = new wizard[a];//create a dynamic array
	return people;
}

/***********************************************************************
 * Function: spellbook* create_spellbooks
 * Description: create a dynamic array to store spell books
 * Parameters: the size of dynamic array
 * Pre-Conditions: call the function to create the array
 * Post-Conditions:finish creating the array
***********************************************************************/

struct spellbook* create_spellbooks(int a){
	struct spellbook *book = new spellbook[a];//create a dynamic array
	return book;
}

/***********************************************************************
 * Function: spell* create_spells
 * Description: create a dynamic array to store the spells
 * Parameters: the size of dynamic array
 * Pre-Conditions: call the function to create the array
 * Post-Conditions: finish creating the array
***********************************************************************/

struct spell* create_spells(int a){
	struct spell *sp = new spell[a];//create a dynamic array
	return sp;
}

/***********************************************************************
 * Function: open_wizard
 * Description: open the file and store the information about the wizard into the array
 * Parameters: the dynamic,the size of dynamic array,the name of the file
 * Pre-Conditions: call the function to store information
 * Post-Conditions: finish storing the information
***********************************************************************/

void open_wizard(wizard *people,char **argv,int peop){
	string filename = argv[1];
	ifstream f1;
	f1.open(filename.c_str(),ifstream::in);//open the file
	string a;
	getline(f1,a);
	for (int i=0;i<peop;i++){
		f1 >> people[i].name;//input the information into the array
		f1 >> people[i].id;
		f1 >> people[i].password;
		f1 >> people[i].position_title;
		f1 >> people[i].num_years_employed;
	}
	f1.close();
}

/***********************************************************************
 * Function: check_numb
 * Description: check whehter the ID number consists of integer or not
 * Parameters: ID number
 * Pre-Conditions: call the function to check the ID
 * Post-Conditions: finish checking the ID
***********************************************************************/

bool check_numb(string id){
	int a = 0;
	for (unsigned int i=0;i<id.length();i++){
		if (id[i]<48||id[i]>57){//check each character to make sure the ID consists of integer
			a+=1;	
		}
	}
	if (a!=0){
		cout << "You did not enter a valid ID!\n" << "The characters of ID must be all integers." << endl;
		return false;
	}
	else {
		return true;
	}
}

/***********************************************************************
 * Function: math
 * Description: check whehter the user input the correct ID and password
 * Parameters: the array storing the information about wizard,ID,pin,the size of array,whether the user is student or not
 * Pre-Conditions: call the function to check whether the ID and pin is correct or not
 * Post-Conditions: finish checking
***********************************************************************/

bool math(wizard *people,string id,string pin,int peop,int &adult){
	int idn=atoi(id.c_str());
	for (int i=0;i<peop;i++){
		if ((people[i].id==idn)&&(people[i].password==pin)){//check the ID and pin belong to same person or not
			if ((people[i].position_title=="Student")||(people[i].position_title=="student")){//student or teacher,can see the dangerous spells or not
				adult=18;
			}
			else{
				adult=21;
			}
			cout << " \n" << "Welcome " << people[i].name << endl << "ID: " << people[i].id << endl << "Status: " << people[i].position_title << endl << "Years of experience: " << people[i].num_years_employed << endl;//print the information after logining successfully
			return true;
		}
	}
	cout << "Your ID or password is incorrect!!\n";
	return false;
}

/***********************************************************************
 * Function: login
 * Description: ask the user to input the ID and pin
 * Parameters: the dynamic array storing the information about wizard,the size of array,student or teacher
 * Pre-Conditions: let the user login
 * Post-Conditions: the user logins successfully
***********************************************************************/

void login(wizard *people,int peop,int &adult){
	string id,pin;
	cout << "\n" << "Welcome to the library system!!\n" ;
	do{
		do{
			cout << "Please enter your ID: ";
			cin >> id;
		}while(check_numb(id)==false);//check the ID consists of integer or not
		cout << "Please enter your password: ";
		cin >> pin;
	}while(math(people,id,pin,peop,adult)==false);//check the ID and pin
}

/***********************************************************************
 * Function: danger
 * Description: check whether the spell books have the spells that can cause death or poison
 * Parameters: the dynamic storing the information about spell
 * Pre-Conditions: check the spell is dangerous or not
 * Post-Conditions: finish checking
***********************************************************************/

bool danger(spell *s,int a){
	int num=0;
	for (int i=0;i<a;i++){
		if ((s[i].effect=="death")||(s[i].effect=="poison")){
			num+=1;
		}
	}
	if (num==0){
		return false;
	}
	else{
		return true;
	}
}

/***********************************************************************
 * Function: get_spell_date
 * Description: input the information about spells into an array
 * Parameters: the dynamic array,the size of the array,the file
 * Pre-Conditions: call the function to store the information
 * Post-Conditions: input all the information
***********************************************************************/

void get_spell_data(spell *s, int a,ifstream &f2){
	for (int i=0;i<a;i++){
		f2 >> s[i].name;
		f2 >> s[i].success_rate;
		f2 >> s[i].effect;
	}
}

/***********************************************************************
 * Function: get_spellbook_data
 * Description: input the information about spell books into the array
 * Parameters: the dynamic array, the size of the array,the file
 * Pre-Conditions: call the function to store the information
 * Post-Conditions: finish storing the informaiton
***********************************************************************/

void get_spellbook_data(spellbook *book,int boo,ifstream &f2){
	string a;
	getline(f2,a);
	for (int i=0;i<boo;i++){
		f2 >> book[i].title;
		f2 >> book[i].author;
		f2 >> book[i].num_pages;
		f2 >> book[i].edition;
		f2 >> book[i].num_spells;
		book[i].s=create_spells(book[i].num_spells);//create an array to store the spells
		get_spell_data(book[i].s,book[i].num_spells,f2);
		float b =0;
		for (int x=0;x<book[i].num_spells;x++){
			b=b+book[i].s[x].success_rate;//compute the average success rate of the book
		}
		book[i].avg_success_rate=b/book[i].num_spells;
		book[i].is_dangerous=danger(book[i].s,book[i].num_spells);//check whether the spell book has the dangerous spells or not
	}
}

/***********************************************************************
 * Function: get_book
 * Description: store the information about spell books into the array
 * Parameters: the dynamic array, the size of the array, the name of the file
 * Pre-Conditions: call the function to store the information
 * Post-Conditions: finish storing
***********************************************************************/

void get_book(char **argv,spellbook *book,int boo){
	ifstream f2;
	f2.open(argv[2],ifstream::in);//open the file
	get_spellbook_data(book,boo,f2);
}

/***********************************************************************
 * Function: get_under
 * Description: get the array no danger spells is stored
 * Parameters: the array storing the information about spell books,the size of the array,the size of the new array
 * Pre-Conditions: when the user is a student sort the spell books by page number
 * Post-Conditions: finish creating the array
***********************************************************************/

page* get_under(spellbook *book,int boo,int adult,int &many){
	many=0;
	for (int i=0;i<boo;i++){
		if (book[i].is_dangerous==false){
			many+=1;//find the size of the new array(get the number of safe spell books
		}
	}
	struct page *books = new page[many];
	int a=0;
	for (int i=0;i<boo;i++){
		if (book[i].is_dangerous==false){//input the information into the array
			books[a].name=book[i].title;
			books[a].number=book[i].num_pages;
			a+=1;
		}
	}
	return books;
}

/***********************************************************************
 * Function: order
 * Description: change the order of the number of pages to a descending order
 * Parameters: the dynamic array storing the information, the size of the array
 * Pre-Conditions: already get the array
 * Post-Conditions: finish changing the order
***********************************************************************/

void order(page *books,int many){
	for (int x=0;x<many-1;x++){
		for (int y=0;y<many-1-x;y++){
			struct page mider;
			if(books[y].number<books[y+1].number){//moving the small number to the right
				mider=books[y+1];
				books[y+1]=books[y];
				books[y]=mider;
			}
		}
	}
}

/***********************************************************************
 * Function: way1
 * Description: show the spell books by page number
 * Parameters: the dynamic storing the information about the spell books,the size of the array,student or teacher
 * Pre-Conditions: the user input "1" and want sort the spell books by page number
 * Post-Conditions: print the list on the screen
***********************************************************************/

void way1(spellbook *book,int boo,int adult){
	int many=boo;
	struct page *books;//create a new array to store the name and the page number
	if (adult==21){
		books = new page[boo];
		for (int i=0;i<boo;i++){
			books[i].name=book[i].title;
			books[i].number=book[i].num_pages;
		}
	}
	else if (adult==18){
		books = get_under(book,boo,adult,many);//the array can not store the dangerous spells
	}
	order(books,many);
	for (int x=0;x<many;x++){
		cout << books[x].name << " " << books[x].number << endl;
	}
	delete []books;
}

/***********************************************************************
 * Function: find number
 * Description: find the number of spells for each effect
 * Parameters: the dynamic array storing the information about the spell books, the size of the array, the number of each kinds of spells
 * Pre-Conditions: before creating the 2-D array to store the spells by the effect
 * Post-Conditions: get the number of different types of spell
***********************************************************************/

void find_number(spellbook *book,int boo,int &fir,int &bub,int &mem,int &dea,int &poi){
	for (int x=0;x<boo;x++){
		for (int y=0;y<book[x].num_spells;y++){
			if(book[x].s[y].effect=="memory_loss"){
				mem+=1;
			}
			else if (book[x].s[y].effect=="bubble"){
				bub+=1;
			}
			else if (book[x].s[y].effect=="fire"){
				fir+=1;
			}
			else if (book[x].s[y].effect=="poison"){
				poi+=1;
			}
			else if (book[x].s[y].effect=="death"){
				dea+=1;
			}
		}
	}
}

/***********************************************************************
 * Function:get_number 
 * Description: storing the spells by effect into an array
 * Parameters: the dynamic storing the information about the spell books, the size of the array,the new array
 * Pre-Conditions: call the function to storing the information by effect
 * Post-Conditions: store all the spells
***********************************************************************/

void get_number(spellbook *book,int boo,eff **books){
	int a=0,b=0,c=0,d=0,e=0;
	for (int x=0;x<boo;x++){
		for (int y=0;y<book[x].num_spells;y++){
			if(book[x].s[y].effect=="memory_loss"){
				books[0][a].name=book[x].s[y].name;
				a+=1;
			}
			else if (book[x].s[y].effect=="bubble"){
				books[1][b].name=book[x].s[y].name;
				b+=1;
			}
			else if (book[x].s[y].effect=="fire"){
				books[2][c].name=book[x].s[y].name;
				c+=1;
			}
			else if (book[x].s[y].effect=="poison"){
				books[3][d].name=book[x].s[y].name;
				d+=1;
			}
			else if (book[x].s[y].effect=="death"){
				books[4][e].name=book[x].s[y].name;
				e+=1;
			}
		}
	}
}

/***********************************************************************
 * Function: get_array
 * Description: print the spells by effect on the screen
 * Parameters: the array storing the spells by effect and its size,the array storing the spell books and its size
 * Pre-Conditions: call the function to pring the spell by effect
 * Post-Conditions: pring all the informaiton
***********************************************************************/

void get_array(spellbook *book,int boo,int adult,eff **books,int mem,int bub,int fir,int poi,int dea){
	get_number(book,boo,books);
	for (int a=0;a<mem;a++){
		books[0][a].effect="memory_loss";
		cout << books[0][a].effect << " " << books[0][a].name << endl;
	}
	for (int b=0;b<bub;b++){
		books[1][b].effect="bubble";
		cout << books[1][b].effect << " " << books[1][b].name << endl;
	}
	for (int c=0;c<fir;c++){
		books[2][c].effect="fire";
		cout << books[2][c].effect << " " << books[2][c].name << endl;
	}
	if (adult==21){//the student can not see the dangerous spells
		for (int d=0;d<poi;d++){
			books[3][d].effect="poison";
			cout << books[3][d].effect << " " << books[3][d].name << endl;
		}
		for (int e=0;e<dea;e++){
			books[4][e].effect="death";
			cout << books[4][e].effect << " " << books[4][e].name << endl;
		}
	}
}

/***********************************************************************
 * Function: delete_books
 * Description: delete the new array which stores the spells by its effect
 * Parameters: the array storing the informaiton about spell
 * Pre-Conditions: call the function to delete the array, after printing the spells by effect
 * Post-Conditions: delete the array
***********************************************************************/

void delete_books(eff **books){
	for (int i=0;i<5;i++){
		delete []books[i];
	}
	delete []books;
}

/***********************************************************************
 * Function: way2
 * Description: print the spells by effect
 * Parameters: the array storing the information about spell books and its size, whether the user is a student or teacher
 * Pre-Conditions: the user choose the second way and want to print the spells by effect
 * Post-Conditions: print the spells by effect
***********************************************************************/

void way2(spellbook *book,int boo,int adult){
	int fir=0,bub=0,mem=0,dea=0,poi=0;
	find_number(book,boo,fir,bub,mem,dea,poi);
	struct eff **books = new eff*[5];//create a new array to store the spell name and effect
	books[0]=new eff[mem];
	books[1]=new eff[bub];
	books[2]=new eff[fir];
	books[3]=new eff[poi];
	books[4]=new eff[dea];
	get_array(book,boo,adult,books,mem,bub,fir,poi,dea);
	delete_books(books);
}

/***********************************************************************
 * Function: get_young
 * Description: get the array which does not store the dangerous spell books
 * Parameters: the array storing the information about all the spell books and its size, the size of the new array
 * Pre-Conditions: call the function to create a new array to store the spell books by the average success rate
 * Post-Conditions: finish creating the new array
***********************************************************************/

rate* get_young(spellbook *book,int boo,int &much){
	much=0;
	for (int i=0;i<boo;i++){//find the size of the new array
		if (book[i].is_dangerous==false){
			much+=1;
		}
	}
	struct rate *books = new rate[much];
	int a=0;
	for (int x=0;x<boo;x++){
		if (book[x].is_dangerous==false){
			books[a].name=book[x].title;
			books[a].avg=book[x].avg_success_rate;
			a+=1;
		}
	}
	return books;
}

/***********************************************************************
 * Function: order2
 * Description: change the order of the spell books in a descending order by average success rate
 * Parameters: the new array storing the name and the average success rate of spell books
 * Pre-Conditions: after creating the array and storing the information
 * Post-Conditions: change all the order in a descending order
***********************************************************************/

void order2(rate *books,int much){
	for (int x=0;x<much-1;x++){
		for (int y=0;y<much-1-x;y++){
			struct rate mider;
			if (books[y].avg<books[y+1].avg){//moving the smaller one to the right
				mider=books[y+1];
				books[y+1]=books[y];
				books[y]=mider;
			}
		}
	}
}

/***********************************************************************
 * Function: ways
 * Description: print the spell books on the screen by its average success rate
 * Parameters: the array storing all the informationa about spell books
 * Pre-Conditions:the user enter "3" and want the program show the spell books by the average success rate
 * Post-Conditions: print the spell books by the average success rate
***********************************************************************/

void way3(spellbook *book,int boo,int adult){
	int much=boo;
	struct rate *books;
	if (adult==21){
		books = new rate[much];
		for (int i=0;i<much;i++){
			books[i].name=book[i].title;
			books[i].avg=book[i].avg_success_rate;
		}
	}
	else if (adult==18){
		books = get_young(book,boo,much);
	}
	order2(books,much);
	for (int x=0;x<much;x++){//print the information on the screen
		cout << books[x].name << " " << books[x].avg << endl;
	}
	delete []books;
}

/***********************************************************************
 * Function: ways
 * Description: asking the user which way she or he want to sort the information
 * Parameters: the dynamic storing the information about the spell books and its size, whether the user is a student or teacher
 * Pre-Conditions: the user logins successfully
 * Post-Conditions: the user want to quit
***********************************************************************/

void ways(spellbook *book,int boo,int adult){
	string ways;
	do{
		cout << "\n" << "Which option would you like to choose?\n" << "Sort spellbooks by number of pages (Press 1): \n" << "Group spells by their effect (Press 2): \n" << "Sort spellbooks by average success rate (Press 3): \n" << "Quit (Press 4): \n" << "Your answer: ";		
		cin >> ways;
		cout << " \n";
		if (ways=="1"){
			way1(book,boo,adult);
		}
		else if (ways=="2"){
			way2(book,boo,adult);
		}
		else if (ways=="3"){
			way3(book,boo,adult);
		}
		else if ((ways!="1")&&(ways!="2")&&(ways!="3")&&(ways!="4")){
			cout << " \n" <<"The input should be an integer number 1, 2, 3, or 4!\n";
		}
	}while(ways!="4");
}

/***********************************************************************
 * Function: again
 * Description: ask the user whether he or she want to login another account or not
 * Parameters: None
 * Pre-Conditions: the user chose "4" and wants to logout
 * Post-Conditions:
***********************************************************************/

bool again(){
	cout << "Would you like to lgout and lgin another account (y-yes/n-no): ";
	string a;
	cin >> a;
	if (a=="y"){
		return true;
	}
	else{
		return false;
	}
}


/***********************************************************************
 * Function: delete_info
 * Description: delete array storing the information about the wizards and spell books
 * Parameters: arrays storing the information about the wizards the spell books and its size
 * Pre-Conditions: the user wants to quit the program
 * Post-Conditions: delete all the array
***********************************************************************/

void delete_info(wizard **people,int a,spellbook **book,int b){
	for (int i = 0;i < b;i++){
		delete [](*book)[i].s;
	}
	delete []*book;
	*book = NULL;
	delete []*people;
	*people = NULL;
}


