#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <cstring>

using namespace std;
/*
 * build up this struct to store the information about wizard
 */

struct wizard{
	string name;
	int id;
	string password;
	string position_title;
	int num_years_employed;	
};

/*
 * build up this struct to store the information about spellbooks which includes the information about spells
 */

struct spellbook{
	string title;
	string author;
	bool is_dangerous;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};

/*
 * build up this struct to store the information about spells
 */

struct spell{
	string name;
	float success_rate;
	string effect;
};

/*
 * build up this struct to store the spell books by page number
 */

struct page{
	string name;
	int number;
};

/*
 * build up this struct to store the spell books by average success rate
 */

struct rate{
	string name;
	float avg;
};

/*
 * build up this struct to store the spells by effect
 */

struct eff{
	string effect;
	string name;
};

bool name_righ(char **,int,int &);
struct wizard* create_wizard(int);
struct spellbook* create_spellbooks(int);
struct spell *create_spells(int);
void open_wizard(wizard *,char **,int);
bool check_numb(string);
bool math(wizard *,string,string,int,int &);
void login(wizard *,int,int &);
bool danger(spell *s,int);
void get_spell_data(spell *,int,ifstream &);
void get_spellbook_data(spellbook *,int,ifstream &);
void get_book(char **,spellbook *,int);
page* get_under(spellbook *,int,int,int &);
void order(page *,int);
void way1(spellbook *,int,int);
void fin_number(spellbook *,int,int &,int &,int &,int &,int &);
void get_number(spellbook *,int,eff **);
void get_array(spellbook *,int,int,eff **,int,int,int,int,int);
void delete_books(eff **);
void way2(spellbook *,int,int);
rate* get_young(spellbook *,int,int &);
void order2(rate *,int);
void way3(spellbook *,int,int);
void ways(spellbook *,int,int);
bool again();
void delete_info(wizard **,int,spellbook **,int);


#endif
