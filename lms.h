#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED
#endif // LMS_H_INCLUDED
#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED
#endif // LMS_H_INCLUDED
struct addUser{
char userid[20];
char pwd[20];
};
struct Category{
int id;
char cat_name[20];
};
struct Book{
int bookid;
char bookname[50];
char authorName[50];
char cat_name[50];
int quantity;
};
struct Student{
int roll;
char name[30];
};
struct IssueBook{
int roll;
int bookid;
};
typedef struct IssueBook IssueBook;
typedef struct Student Student;
typedef struct Book book;
typedef struct Category Category;
typedef struct addUser User;
int enterchoice();
void addUser();
void addCategory();
int input();
int isUserPresent(char *,char *);
int showCategory();
book* getBookDetails();
void addbooks(book,int);
void show_books();
int getBookId();
char * getBookName(int);
int searchMenu();
void searchBooks(int);
int showIssueMenu();
//void IssueBook();
void search_issued_books();
void show_issued_books();
int issueBook();
void addStudent();
char * get_book_name(int);
char * get_student_name(int);
void delete_book();
void update_book();
void remove_issued_books();
