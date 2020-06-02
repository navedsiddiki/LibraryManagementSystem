#include"lms.h"
#include<stdio.h>
#include "conio2.h";
void addUser(){
FILE *fp=fopen("user.bin","rb");
if(fp==NULL){
fp=fopen("user.bin","wb");
User u={"admin","abc"};
fwrite(&u,sizeof(u),1,fp);
fclose(fp);
}
fclose(fp);
}
int isUserPresent(char *u,char *p){
if(*(u)==0||*(p)==0){
    gotoxy(45,20);
    textcolor(LIGHTRED);
    printf("BOTH FIELDS ARE MANDATORY");
    getch();
    gotoxy(45,20);
    printf("\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(59,10);
    printf("\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(60,11);
    printf("\t\t\t\t\t\t\t\t\t\t\t");
    return 0;
}
FILE *fp=fopen("user.bin","rb");
User user;
fread(&user,sizeof(User),1,fp);
if(strcmp(u,user.userid)||strcmp(p,user.pwd)){
    gotoxy(40,20);
    textcolor(LIGHTRED);
    printf("INVALID USERNAME OR PASSWORD");
    getch();
    gotoxy(40,20);
   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
   gotoxy(59,10);
   printf("\t\t\t\t\t\t\t\t");
   gotoxy(60,11);
   printf("\t\t\t\t\t\t\t\t");
   textcolor(YELLOW);
   fclose(fp);
   return 0;
}
fclose(fp);
return 1;
}
int input(){
    clrscr();
  int i=0;
  char c;
    char name[30];
  char p[30];
 gotoxy(48,1);
 textcolor(YELLOW);
 printf(":LIBRARY MANAGMENT SYSTEM:");
 gotoxy(1,2);
 for(i=0;i<=119;i++)
 printf("%c",247);

 gotoxy(52,5);
 printf("%c LOGIN PANEL %c",1,1);
 gotoxy(1,7);
 textcolor(LIGHTGREEN);
 for(i=0;i<=119;i++)
 printf("%c",247);
 do{
 gotoxy(45,10);
 textcolor(LIGHTCYAN);
 printf("Enter User Id:");
 gotoxy(45,11);
 printf("Enter Password:");
 textcolor(LIGHTGREEN);
 gotoxy(1,15);
 for(i=0;i<=119;i++)
  printf("%c",247);
 textcolor(WHITE);
 gotoxy(59,10);
 for(i=0;i<=29;i++){
  name[i]=getchar();
  if(name[i]==10)
    break;
 }
 name[i]='\0';
 gotoxy(60,11);
 for(i=0;i<=29;){
     p[i]=getch();
     if(p[i]==13)
     break;
     if(p[i]!=8){
        printf("*");
        i++;
     }
     else{
      i--;
      if(i<0)
      i++;
      else
      printf("\b \b");
     }
 }
 p[i]='\0';
 }while(isUserPresent(name,p)==0);
}
void addCategory(){
FILE *fp=fopen("category.bin","rb");
if(fp==NULL){
    fp=fopen("category.bin","wb");
Category cat[6]={
 {1,"CSE"},
 {2,"EC"},
 {3,"EX"},
 {4,"IT"},
 {5,"ME"},
 {6,"CIVIL"}
};
fwrite(cat,6*sizeof(Category),1,fp);
fclose(fp);
}
else{
    fclose(fp);
}
}
int enterchoice(){
    clrscr();
int choice,i;
textcolor(YELLOW);
gotoxy(48,1);
 printf(":LIBRARY MANAGMENT SYSTEM:\n");
 for(i=1;i<=120;i++)
    printf("%c",247);
    gotoxy(52,4);
    textcolor(LIGHTGREEN);
    printf("%c ADMIN PANEL %c",1,1);
    gotoxy(1,6);
    for(i=1;i<=240;i++)
    printf("%c",176);
    gotoxy(50,9);
    textcolor(YELLOW);
    printf("1- Add Books");
    gotoxy(50,10);
    printf("2- View All Books");
    gotoxy(50,11);
    printf("3- Search Book");
    gotoxy(50,12);
    printf("4- Issue Book");
    gotoxy(50,13);
    printf("5- Update Book");
    gotoxy(50,14);
    printf("6- Delete Book");
     gotoxy(50,15);
    printf("7- Quit");
    gotoxy(1,17);
    textcolor(LIGHTGREEN);
    for(i=1;i<=240;i++)
    printf("%c",176);
    gotoxy(50,20);
    textcolor(YELLOW);
    printf("Enter choice:");
    textcolor(WHITE);
    fflush(stdin);
    scanf("%d",&choice);
    return choice;
}
int showCategory(){
    clrscr();
    int choice;
    int i;
   /* struct category{
    int id;
    char cat_name[20];
    };*/
    Category s;
    FILE *fp=fopen("category.bin","rb");
    if(fp==NULL){
        printf("File does not exist:");
        return 0;
    }
    textcolor(YELLOW);
   gotoxy(48,1);
 printf(":LIBRARY MANAGMENT SYSTEM:\n");
 for(i=1;i<=120;i++)
    printf("%c",247);
    gotoxy(52,5);
    textcolor(LIGHTGREEN);
    printf("* CATEGORIES *");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
    printf("%c",176);
    gotoxy(100,4);
    textcolor(LIGHTCYAN);
    printf("Enter 0 for exit:");
    gotoxy(50,9);
    textcolor(YELLOW);
    for(i=0;fread(&s,sizeof(Category),1,fp)==1;i++){
    gotoxy(50,9+i);
    printf("%d. %s",s.id,s.cat_name);
    }
    gotoxy(1,17);
    textcolor(LIGHTGREEN);
    for(i=1;i<=240;i++)
    printf("%c",176);
    gotoxy(50,20);
    textcolor(YELLOW);
    printf("Select Category:");
    while(1){
    gotoxy(66,20);
    fflush(stdin);
     textcolor(WHITE);
    scanf("%d",&choice);
    if(choice==0)
    exit(0);
     if(choice<1 || choice>6){
      textcolor(LIGHTRED);
      gotoxy(45,25);
      printf("Incorrect Choice:");
      getch();
      gotoxy(45,25);
      printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
      gotoxy(66,20);
      printf("\t\t\t\t\t");
     }
     else{
        break;
     }
    }
    return choice;
}
int getBookId(){
    int count=100;
  FILE *fp=fopen("book.bin","rb");
  if(fp==NULL){
    return count+1;
  }
  char ch;
  if((ch=fgetc(fp))==-1){
    return count+1;
  }
  //fputc(ch,fp);
  /*fseek(fp,0L,SEEK_END);
  int t=ftell(fp)/sizeof(book);
  fclose(fp);
  count=count+ ++t;
  return count;*/
  fseek(fp,-1L*sizeof(book),SEEK_END);
  int bid;
  fread(&bid,sizeof(bid),1,fp);
  fclose(fp);
  return bid+1;
}
book * getBookDetails(){
static book b;
int i;
textcolor(YELLOW);
gotoxy(50,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
    gotoxy(55,5);
    textcolor(LIGHTGREEN);
    printf("Add Book Panel:");
    gotoxy(1,6);
    for(i=1;i<=240;i++)
        printf("%c",176);
gotoxy(1,17);
for(i=1;i<=240;i++)
    printf("%c",176);
textcolor(YELLOW);
//##Generate book id ##
int id_b=getBookId();
b.bookid=id_b;
gotoxy(19,9);
char *pos;
int valid;
printf("Book Id ");
textcolor(WHITE);
printf("%d",b.bookid);
gotoxy(19,10);
textcolor(YELLOW);
printf("Enter Book Name:");
textcolor(WHITE);
do{
    valid=1;
    fflush(stdin);
    fgets(b.bookname,50,stdin);
    pos=strchr(b.bookname,'\n');
    *pos='\0';
    if(strlen(b.bookname)==0){
        valid=0;
        gotoxy(40,22);
        textcolor(LIGHTRED);
        printf("BOOK NAME IS A MANDATORY FIELD");
        getch();
        textcolor(WHITE);
        printf("\t\t\t\t\t\t");
        gotoxy(40,22);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(35,10);
    }
}while(valid==0);
gotoxy(19,11);
textcolor(YELLOW);
printf("Enter Book Author:");
do{
    textcolor(WHITE);
    valid=1;
    fflush(stdin);
    fgets(b.authorName,50,stdin);
    pos=strchr(b.authorName,'\n');
    *pos='\0';
    int i=0;
    if(strlen(b.authorName)==0){
  valid=0;
  gotoxy(40,22);
  textcolor(LIGHTRED);
  printf("Author name is a mandatory field:");
  getch();
  gotoxy(40,22);
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
  gotoxy(37,11);
  printf("\t\t\t\t\t\t\t\t\t\t\t\t");
  gotoxy(37,11);
    }
    while(i<strlen(b.authorName)){
        if(!(isalpha(b.authorName[i]))){
            valid=0;
            gotoxy(40,22);
      textcolor(LIGHTRED);
      printf("Author name should contains only Alphabet:");
      getch();
      gotoxy(40,22);
      printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
      gotoxy(37,11);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t");
      gotoxy(37,11);
      break;
        }
        i++;
    }
}while(valid==0);
gotoxy(19,12);
textcolor(YELLOW);
printf("Enter Book Quantity:");
do{
    textcolor(WHITE);
    valid=1;
    fflush(stdin);
    int check=scanf("%d",&b.quantity);
    if(check==0 || b.quantity<=0){
    valid=0;
    gotoxy(42,22);
    textcolor(LIGHTRED);
    printf("Quantity should be valid:");
    getch();
    gotoxy(42,22);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(39,12);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(39,12);
    }
}while(valid==0);
return (&b);
}
void addbooks(book b,int i){
FILE *fp=fopen("book.bin","ab");
if(fp==NULL){
    printf("File can not be opend:");
    return;
}
/*FILE *p=fopen("category.bin","rb");
if(p==NULL){
    printf("File can not be opend:");
    return;
}
/*Category s;
int a;
for(a=0;fread(&s,sizeof(Category),1,p)==1;a++){
   if(i==s.id)
    break;
}*/
 /*int a;
 for(a=0;fread(&s,sizeof(Category),1,p)==1;a++)
 {
     if(i==s.id)
     {
          fseek(fp,0L,SEEK_END);
          strcpy(b.cat_name,s.cat_name);
          fwrite(&b,sizeof(book),1,fp);
          break;
     }
 }
 fclose(fp);
}*/
 fseek(fp,0L,SEEK_END);
 strcpy(b.cat_name,getBookName(i));
 fwrite(&b,sizeof(book),1,fp);
fclose(fp);
}
char * getBookName(int i){
    FILE *p=fopen("category.bin","rb");
if(p==NULL){
    printf("File can not be opend:");
    return;
}
Category s;
int a;
static char cname[20];
for(a=0;fread(&s,sizeof(Category),1,p)==1;a++){
   if(i==s.id){
   	strcpy(cname,s.cat_name);
   	fclose(p);
   	return cname;
   }
}
 fclose(p);
   return NULL;
}
void show_books(){
FILE *fp=fopen("book.bin","rb");
if(fp==NULL){
    gotoxy(46,15);
    textcolor(LIGHTRED);
    printf("NO SUCH BOOK RECORDS FOUND!");
    return;
}
book b;
int a;
int i;
int y=7;
textcolor(LIGHTGREEN);
for(i=0;i<120;i++)
 printf("%c",176);
textcolor(LIGHTCYAN);
gotoxy(53,2);
printf("%c  ALL BOOKS  %c",1,1);
gotoxy(1,3);
textcolor(LIGHTGREEN);
for(i=0;i<240;i++){
    printf("%c",176);
}
gotoxy(4,6);
printf("\tBook Name\t\tAuthor Name\t\tBook Id\t\t   Quantity\t\t   Category");
textcolor(YELLOW);
for(a=0;fread(&b,sizeof(book),1,fp)==1;a++){
       gotoxy(7,y);
printf("\t%s\t\t\t%s  \t\t%d\t\t    %d\t\t\t    %s",b.bookname,b.authorName,b.bookid,b.quantity,b.cat_name);
y++;
}
textcolor(WHITE);
}
int searchMenu(){
int choice,i;
textcolor(YELLOW);
gotoxy(50,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
gotoxy(53,4);
textcolor(LIGHTGREEN);
printf("%c SEARCH PANEL %c",1,1);
//FOR UPPER BORDER
gotoxy(1,6);
for(i=1;i<=120;i++)
    printf("%c",176);
//for lower border
gotoxy(1,16);
for(i=1;i<=240;i++)
    printf("%c",176);
int ch;
gotoxy(30,10);
textcolor(YELLOW);
printf("1. Search book by id:");
gotoxy(30,11);
printf("2. Search book by name:");
gotoxy(30,13);
textcolor(LIGHTGREEN);
printf("Enter your choice:");
textcolor(WHITE);
while(1){
        fflush(stdin);
    scanf("%d",&ch);
    if(ch<1 || ch>2){
    gotoxy(45,21);
    textcolor(LIGHTRED);
    printf("Incorrect Choice:");
    getch();
    gotoxy(30,18);
    printf("\t\t\t\t");
    gotoxy(48,13);
    printf("\t\t\t");
    gotoxy(45,21);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    gotoxy(48,13);
    textcolor(WHITE);
    }
    else
    return ch;
}
}
void searchBooks(int ch){
int i;
clrscr();
textcolor(YELLOW);
gotoxy(50,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
gotoxy(53,4);
textcolor(LIGHTGREEN);
printf("%c SEARCH PANEL %c",1,1);
//for upper border
gotoxy(1,6);
for(i=1;i<=240;i++)
    printf("%c",176);
//for lower border
gotoxy(1,19);
for(i=1;i<=240;i++)
    printf("%c",176);
int id,f=0;book b;char bName[50];
int result;
FILE *fp=fopen("book.bin","rb");
if(ch==1){
    gotoxy(33,10);
    textcolor(YELLOW);
    printf("Enter Book Id:");
    textcolor(WHITE);
    scanf("%d",&id);
}
else if(ch==2){
    gotoxy(33,10);
    textcolor(YELLOW);
    printf("Enter Book Name you want to search:");
    fflush(stdin);
    textcolor(WHITE);
    gets(bName);
}
while(fread(&b,sizeof(book),1,fp)==1){
    result=(ch==1)?(id==b.bookid):(strcmpi(bName,b.bookname)==0);
    if(result==1){
        gotoxy(33,12);
        textcolor(LIGHTGREEN);
        printf("Book is Available");
        textcolor(LIGHTCYAN);
        gotoxy(33,14);
        printf("Book Id : %d",b.bookid);
        gotoxy(33,15);
        printf("Book name : %s",b.bookname);
        gotoxy(33,16);
        printf("Quantity : %d",b.quantity);
        gotoxy(33,17);
        printf("Author Name : %s",b.authorName);
        f=1;
        getch();
    }
}
if(f==0){
    gotoxy(50,16);
    textcolor(LIGHTRED);
    printf("No Book Found:");
}
fclose(fp);
}
//start debugging from here
int showIssueMenu(){
    int i;
    int choice;
textcolor(YELLOW);
gotoxy(50,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
gotoxy(53,4);
textcolor(LIGHTGREEN);
printf("%c SEARCH PANEL %c",1,1);
//FOR UPPER BORDER
gotoxy(1,6);
for(i=1;i<=240;i++)
    printf("%c",176);
//for lower border
gotoxy(1,19);
for(i=1;i<=240;i++)
    printf("%c",176);
    textcolor(YELLOW);
 gotoxy(45,11);
 printf("1. Issue a Book        %c",1);
 gotoxy(45,12);
 printf("2. View Issued Book    %c",1);
 gotoxy(45,13);
 printf("3. Search Issued Book  %c",1);
 gotoxy(45,14);
 printf("4. Remove Issued Book  %c",1);
 gotoxy(45,15);
 printf("5. Quit");
 gotoxy(68,15);
 textcolor(LIGHTRED);
 printf("%c",'X');
 textcolor(LIGHTGREEN);
 gotoxy(45,25);
 printf("Enter Your Choice:");
 textcolor(WHITE);
 while(1){
     fflush(stdin);
    scanf("%d",&choice);
 if(choice<1 || choice>5){
    gotoxy(43,27);
 textcolor(LIGHTRED);
 printf("Please Enter Valid Option!");
 getch();
 gotoxy(43,27);
 printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
  gotoxy(63,25);
  printf("\t\t\t\t\t");
  textcolor(WHITE);
  gotoxy(63,25);
 }
  else
   return choice;
}
}
void addStudent(){
FILE *fp=fopen("student.bin","rb");
if(fp==NULL){
    fp=fopen("student.bin","wb");
    Student stu[10]={
       {101,"ajay"},
        {102,"amit kumar"},
         {103,"ram kumar"},
          {104,"arpit"},
           {105,"pankaj"},
            {106,"amrita"},
             {107,"rashmi sharma"},
              {108,"sonu"},
               {109,"rishabh"},
                {110,"sohel"}
    };
    fwrite(stu,10*sizeof(Student),1,fp);
    fclose(fp);
}
else{
    printf("Exist");
    fclose(fp);
}
}
int issueBook(){
int bookId,i;
book b;
int bookfound=0,bookq=0;
Student stu;
int roll;
FILE *fpi=fopen("issuebook.bin","ab");
FILE *fp=fopen("book.bin","rb+");
FILE *fps=fopen("student.bin","rb");
if(fpi==NULL || fp==NULL || fps==NULL){
    return 0;
}
textcolor(YELLOW);
gotoxy(48,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
gotoxy(50,4);
textcolor(LIGHTGREEN);
printf("%c BOOK ISSUE PANEL %c",1,1);
//for upper border
gotoxy(1,6);
for(i=1;i<=240;i++)
printf("%c",176);
//for lower border
gotoxy(1,16);
for(i=1;i<=240;i++)
    printf("%c",176);
gotoxy(25,10);
printf("Enter book id to be issued:");
textcolor(WHITE);
scanf("%d",&bookId);
while(fread(&b,sizeof(book),1,fp)==1){
    if(b.bookid==bookId){
    bookfound=1;
    if(b.quantity>0){
        bookq=1;
    }
    break;
    }
}
if(bookfound==0){
    gotoxy(46,20);
    textcolor(LIGHTRED);
    printf("No book found with id %d",bookId);
    getch();
    fclose(fpi);
    fclose(fp);
    fclose(fps);
    return 0;
}
if(bookq==0){
    gotoxy(47,20);
    textcolor(LIGHTRED);
    printf("Out of Stock");
    getch();
    fclose(fpi);
    fclose(fp);
    fclose(fps);
    return 0;
}
int stufound=0;
gotoxy(25,11);
textcolor(LIGHTGREEN);
printf("Enter Student roll no.");
textcolor(WHITE);
scanf("%d",&roll);
while(fread(&stu,sizeof(Student),1,fps)==1){
    if(stu.roll==roll){
        stufound=1;
        break;
    }
}
if(stufound==0){
    gotoxy(45,19);
    textcolor(LIGHTRED);
    printf("Incorrect roll no.");
    getch();
    fclose(fp);
    fclose(fpi);
    fclose(fps);
    return 0;
}
IssueBook ib;
ib.roll=roll;
ib.bookid=bookId;
fwrite(&ib,sizeof(ib),1,fpi);
//update book quantity
fseek(fp,-4,SEEK_CUR);
int quant=b.quantity-1;
fwrite(&quant,sizeof(quant),1,fp);
 fclose(fp);
    fclose(fpi);
    fclose(fps);
    return 1;
}
char * get_book_name(int bid){
FILE *fp=fopen("book.bin","rb");
book b;
static char bname[50];
while(fread(&b,sizeof(book),1,fp)==1){
    if(b.bookid==bid){
        strcpy(bname,b.bookname);
        fclose(fp);
        return bname;
    }
}
fclose(fp);
return NULL;
}
void show_issued_books(){
IssueBook t;
int i;
textcolor(YELLOW);
gotoxy(48,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++){
    printf("%c",247);
}
gotoxy(48,4);
textcolor(LIGHTGREEN);
printf("%c ISSUED BOOKS DETAILS %c",1,1);
gotoxy(1,6);
for(i=1;i<=240;i++)
    printf("%c",176);
textcolor(YELLOW);
gotoxy(30,8);
printf("Roll Number\t      Book  Name");
FILE *fp=fopen("issuebook.bin","rb");
int y=9;
while(fread(&t,sizeof(IssueBook),1,fp)==1){
    gotoxy(33,y);
    textcolor(YELLOW);
    printf("%d",t.roll);
    gotoxy(57,y);
    //get book name
    printf("%s",get_book_name(t.bookid));
    y++;
}
textcolor(LIGHTGREEN);
printf("\n");
for(i=1;i<=240;i++)
    printf("%c",176);
fclose(fp);
}
void search_issued_books(){
 int i;
 int id,f=0;
 IssueBook ib;
 clrscr();
 textcolor(YELLOW);
 gotoxy(48,1);
printf(":LIBRARY MANAGMENT SYSTEM:\n");
for(i=1;i<=120;i++)
    printf("%c",247);
gotoxy(50,4);
textcolor(LIGHTGREEN);
printf("%c BOOK SEARCH PANEL %c",1,1);
//for upper border
gotoxy(1,6);
for(i=1;i<=240;i++)
printf("%c",176);
//for lower border
gotoxy(1,25);
for(i=1;i<=240;i++)
    printf("%c",176);
 FILE *fp=fopen("issuebook.bin","rb");
 gotoxy(31,10);
 textcolor(LIGHTGREEN);
 printf("Enter book id to be searched:");
 textcolor(WHITE);
 scanf("%d",&id);
 textcolor(LIGHTGREEN);
 while(fread(&ib,sizeof(IssueBook),1,fp)==1){
    if(id==ib.bookid){
        gotoxy(30,12);
        textcolor(LIGHTGREEN);
        printf("ISsued book details:");
        textcolor(LIGHTCYAN);
        gotoxy(30,14);
        printf("Roll no. : %d ",ib.roll);
        gotoxy(30,15);
        printf("Student name : %s ",get_student_name(ib.roll));
        gotoxy(30,16);
        printf("Book id : %d ",ib.bookid);
        gotoxy(30,17);
        printf("Book name : %s ",get_book_name(ib.bookid));
        f=1;
        getch();
    }
 }
 if(f==0){
    gotoxy(31,15);
    textcolor(LIGHTRED);
    printf("No details of book %d found in issued books",id);
 }
 }
 char * get_student_name(int id){
 FILE *fp=fopen("student.bin","rb");
Student s;
static char sname[50];
while(fread(&s,sizeof(Student),1,fp)==1){
    if(s.roll==id){
        strcpy(sname,s.name);
        fclose(fp);
        return sname;
    }
 }
 fclose(fp);
 return NULL;
 }
 void delete_book(){
 int i;
 int result;
 int id,f=0;
 book b;
 clrscr();
 textcolor(LIGHTGREEN);
gotoxy(47,1);
 printf(":LIBRARY MANAGMENT SYSTEM:\n");
 for(i=1;i<=240;i++)
    printf("%c",176);
 gotoxy(50,4);
 printf("%c DELETE BOOKS %c",1,1);
 //ro upper border
 gotoxy(1,5);
 for(i=1;i<=240;i++)
 printf("%c",176);
 //for lower border
 gotoxy(1,23);
 for(i=1;i<=240;i++)
    printf("%c",176);
    FILE *fp=fopen("book.bin","rb");
    gotoxy(30,10);
    textcolor(YELLOW);
    printf("Enter book id :");
    textcolor(WHITE);
    scanf("%d",&id);
    fseek(fp,0L,SEEK_END);
    long rec_count=ftell(fp)/sizeof(book);
    rewind(fp);
    book *p=(book *)malloc((rec_count)*sizeof(book));
    i=0;
    while(fread(&b,sizeof(book),1,fp)){
        if(id!=b.bookid){
      *(p+i)=b;
      i++;
        }
        else
     f=1;
    }
    if(f==0){
        gotoxy(33,15);
        textcolor(LIGHTRED);
        printf("No Book Found of id %d",id);
        fclose(fp);
        free(p);
        return;
    }
    fp=fopen("book.bin","wb");
    fwrite(p,i*sizeof(book),1,fp);
    fclose(fp);
    free(p);
    gotoxy(36,18);
    textcolor(LIGHTGREEN);
    printf("Book of id %d deleted successfully:",id);
    return;
 }
void update_book(){
    char choice;
    do{
int c=0;
int d,e;
book b;
FILE *fp;
int i;
clrscr();
 textcolor(LIGHTGREEN);
gotoxy(47,1);
 printf(":LIBRARY MANAGMENT SYSTEM:\n");
 for(i=1;i<=240;i++)
    printf("%c",176);
 gotoxy(50,4);
 printf("%c UPDATE BOOKS %c",1,1);
 //ro upper border
 gotoxy(1,5);
 for(i=1;i<=240;i++)
 printf("%c",176);
 //for lower border
 gotoxy(1,27);
 for(i=1;i<=240;i++)
    printf("%c",176);
gotoxy(26,8);
printf("Enter Book Id to be updated:");
textcolor(WHITE);
scanf("%d",&d);
fp=fopen("book.bin","rb+");
while(fread(&b,sizeof(book),1,fp)==1){
  if(d==b.bookid)
  {
      c=1;
      break;
  }
}
if(c==0)
{
textcolor(LIGHTRED);
gotoxy(45,16);
printf("NO RECORD FOUND WITH ID %d",d);
getch();
return;
}
textcolor(LIGHTGREEN);
gotoxy(38,11);
printf("Book is available details are below:");
gotoxy(38,13);
textcolor(LIGHTCYAN);
printf("Book id is : %d",b.bookid);
gotoxy(38,14);
printf("Book name is : %s",b.bookname);
gotoxy(38,15);
printf("Book author name is : %s",b.authorName);
gotoxy(38,16);
printf("Book quantity is : %d",b.quantity);
gotoxy(38,17);
printf("Book category is : %s",b.cat_name);
textcolor(LIGHTGREEN);
gotoxy(26,20);
fflush(stdin);
printf("Enter new book name:");
textcolor(WHITE);
scanf("%s",&b.bookname);
gotoxy(26,20);
textcolor(LIGHTGREEN);
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
gotoxy(26,20);
fflush(stdin);
printf("Enter new author name:");
textcolor(WHITE);
scanf("%s",&b.authorName);
gotoxy(26,20);
textcolor(LIGHTGREEN);
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
gotoxy(26,20);
fflush(stdin);
printf("Enter new quantity of book:");
textcolor(WHITE);
scanf("%d",&b.quantity);
gotoxy(26,20);
textcolor(LIGHTGREEN);
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
gotoxy(26,20);
fflush(stdin);
printf("Enter new category name:");
textcolor(WHITE);
scanf("%s",b.cat_name);
fseek(fp,ftell(fp)-sizeof(book),0);
fwrite(&b,sizeof(book),1,fp);
fclose(fp);
textcolor(LIGHTGREEN);
gotoxy(26,20);
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
gotoxy(40,22);
printf("RECORD SUCCESSFULLY UPDATED!");
gotoxy(33,24);
printf("Do you want to update another recored?(Y/N):");
textcolor(WHITE);
fflush(stdin);
scanf("%c",&choice);
}while(choice=='y' || choice=='Y');

}
void remove_issued_books(){
 int i;
 int result;
 int id,f=0;
 IssueBook b;
 clrscr();
 textcolor(LIGHTGREEN);
gotoxy(47,1);
 printf(":LIBRARY MANAGMENT SYSTEM:\n");
 for(i=1;i<=240;i++)
    printf("%c",176);
 gotoxy(50,4);
 printf("%c REMOVE BOOKS %c",1,1);
 //ro upper border
 gotoxy(1,5);
 for(i=1;i<=240;i++)
 printf("%c",176);
 //for lower border
 gotoxy(1,27);
 for(i=1;i<=240;i++)
    printf("%c",176);
    FILE *fp=fopen("issuebook.bin","rb");
    gotoxy(30,10);
    textcolor(YELLOW);
    printf("Enter book id :");
    textcolor(WHITE);
    scanf("%d",&id);
    fseek(fp,0L,SEEK_END);
    long rec_count=ftell(fp)/sizeof(IssueBook);
    rewind(fp);
    IssueBook *p=(IssueBook *)malloc((rec_count)*sizeof(IssueBook));
    i=0;
    while(fread(&b,sizeof(IssueBook),1,fp)){
        if(id!=b.bookid){
      *(p+i)=b;
      i++;
        }
        else{
    book b1;
     f=1;
     FILE *fp1=fopen("book.bin","rb+");
     while(fread(&b1,sizeof(book),1,fp1)==1){
      if(id==b1.bookid)
        break;
     }
     fseek(fp1,-4,SEEK_CUR);
int quant=b1.quantity+1;
fwrite(&quant,sizeof(quant),1,fp1);
fclose(fp1);
        }
    }
    if(f==0){
        gotoxy(33,15);
        textcolor(LIGHTRED);
        printf("No Book Found of id %d",id);
        fclose(fp);
        free(p);
        getch();
        return;
    }
    fp=fopen("issuebook.bin","wb");
    //getch();
    fwrite(p,i*sizeof(IssueBook),1,fp);
    fclose(fp);
    free(p);
    gotoxy(33,15);
    textcolor(LIGHTGREEN);
    printf("Book of id %d deleted successfully:",id);
    return;
}
