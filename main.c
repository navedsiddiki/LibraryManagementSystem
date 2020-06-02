#include <stdio.h>
#include <stdlib.h>
#include "lms.h"
#include "conio2.h"
int main()
{
gotoxy(38,11);
textcolor(YELLOW);
printf(": WELCOME TO LIBRARY MANAGMENT SYSTEM :");
gotoxy(30,14);
textcolor(LIGHTGREEN);
printf("* HAVING FUN IS NOT HARD.WHEN YOU HAVE A LIBRARY CARD %c *",1);
//printf("* Having Fun Is Not Hard.When You Have a Library Card %c *",1);

gotoxy(54,20);
printf("%c%c%c%c%c%c%c%c",1,1,1,1,1,1,1,1);
gotoxy(54,21);
printf("%c",1);
gotoxy(54,22);
printf("%c",1);
gotoxy(54,23);
printf("%c",1);
gotoxy(54,24);
printf("%c",1);
gotoxy(54,25);
printf("%c",1);
gotoxy(54,26);
printf("%c%c%c%c%c%c%c%c",1,1,1,1,1,1,1,1);
gotoxy(61,25);
printf("%c",1);
gotoxy(61,24);
printf("%c",1);
gotoxy(61,23);
printf("%c",1);
gotoxy(61,22);
printf("%c",1);
gotoxy(61,21);
printf("%c",1);
gotoxy(64,26);

getch();
textcolor(YELLOW);
addUser();
addStudent();
input();
addCategory();
clrscr();
int choice;
while(1){
 choice=enterchoice();
 if(choice==7){
    exit(0);
 }
 switch(choice){
 case 1:
     clrscr();
      book *b;
      int i;
      char bchoice;
    do{
     i=showCategory();
     clrscr();
    b=getBookDetails();
    addbooks(*b,i);
    textcolor(LIGHTGREEN);
    gotoxy(45,24);
    printf("Do you want to add more books?(Y/N):");
    fflush(stdin);
    textcolor(WHITE);
    scanf("%c",&bchoice);
    }
    while(bchoice=='Y' || bchoice=='y');
    break;
 case 2:
     clrscr();
     show_books();
     getch();
    break;
 case 3:
     clrscr();
     int ch=searchMenu();
     searchBooks(ch);
     getch();
    break;
 case 4:
     clrscr();
     int c;
     c=showIssueMenu();
     switch(c){
 case 1:
    clrscr();
    int i=issueBook();
    if(i==0){
    gotoxy(47,22);
    printf("BOOKING FAILED!");
    }
    else{
        gotoxy(47,22);
        textcolor(LIGHTGREEN);
        printf("BOOKING SUCCSSFULL!");
    getch();
    }
    break;
 case 2:
    clrscr();
    show_issued_books();
    getch();
    break;
 case 3:
    clrscr();
    search_issued_books();
    getch();
    break;
 case 4:
    clrscr();
    remove_issued_books();
    getch();
    break;
     }
     break;
 case 5:
  clrscr();
   update_book();
    break;
 case 6:
    clrscr();
    delete_book();
    getch();
    break;
}
}
getch();
return 0;
}
