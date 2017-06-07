/*
 
 FOR THE PROJECT CERTAIN PARTS MY COUSIN HELPED ME OUT BY EXPLAINING HOW CERTAIN THINGS WORK: CASE IN POINT STRCPY, STRCMP, AN ATOI...... EVENTHOUGH HE HELPED EXPLAIN TO ME HOW EACH OF THEM WORK, ALL THE CODE WAS TYPED BY MYSELF. MY COUSIN ONLY TOLD ME HINTS AS TO WHY IT WASN'T RUNNING CORRECTLY AND WHAT I NEEDED TO DO IN ORDER TO FIX IT AND GET IT RUNNING. 
 
            SO EVERYTHING IS RUNNING NOW, SO PLEASE RUN THE CODE AND ENJOY MY PROJECT.
        
    - BRANDON SERRANO
                       
 */





#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAX    100

class bookEntry{
public:
    int copies;
    char name[30];
    char author[30];
};


class library{
public:
    int numBooks;
    bookEntry database[MAX];
    
    library(){
        numBooks = 0;
    }
    void insertBook( char bookName[], char author[], int c);
    void deleteBook( char bookName[]);
    bookEntry *search( char bookName[]);
};

void library::insertBook( char bookName[], char author[], int c){
    strcpy( database[numBooks].name, bookName);
    strcpy( database[numBooks].author, author);
    database[numBooks].copies = c;
    cout << "Book Inserted Successfully.\n";
    ++numBooks;
}

void library::deleteBook( char bookName[]){
    int i;
    for( i = 0; i < numBooks; i++){
        if( strcmp( bookName, database[i].name) == 0){
            database[i].copies--;
            cout << "Book Deleted Successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

bookEntry *library::search( char bookName[]){
    int i;
    for( i = 0; i < numBooks; i++){
        if( strcmp( bookName, database[i].name) == 0)
            return &database[i];
    }
    return NULL;
}

int main(){
    library lib;
    
    cout << "\n\n\nBrandon's Final Project\n\n\n" << endl;
    
    char option, name[30], author[30], copies[10];
    while( 1 ){
        cout << "\nPlease Enter Your Option:\n";
        cout << "I To Insert A Book\n";
        cout << "D To Delete A Book\n";
        cout << "S To Search For A Book\n";
        cout << "E To Exit The Program\n";
        
        cin.getline( name, 80);
        option = name[0];
        
        switch( option){
                
            case 'i':
                cout << "Please Enter Name of Book, Author and no of copies per line:\n";
                cin.getline( name, 80);
                cin.getline(author, 80);
                cin.getline(copies, 80);
                lib.insertBook( name, author, atoi(copies));
                break;
            case 'd':
                cout << "Please Enter Name of Book:\n";
                cin.getline(name, 80);
                lib.deleteBook(name);
                break;
            case 's':
                cout << "Please Enter Name of Book:\n";
                cin.getline(name, 80);
                bookEntry *item;
                item = lib.search( name );
                if( item != NULL){
                    cout << "Book found\n" << item->name << endl << item->author << endl << item->copies << endl;
                }
                else
                    cout << "Sorry Book wasn't found\n";
                break;
            case 'e':
                cout << "Thank-You, Good-Bye!" << endl;
                exit(0);
                break;
        }
    }
    return 0;
}
