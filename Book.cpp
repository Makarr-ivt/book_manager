#include "Book.h"

Book::Book() : author(""), title(""), publisher(""), year(0), pages(0) {}

Book::Book(const string& a, const string& t, const string& p, int y, int pg)
    : author(a), title(t), publisher(p), year(y), pages(pg) {}

Book::Book(const Book& other) 
    : author(other.author), title(other.title), 
      publisher(other.publisher), year(other.year), pages(other.pages) {}

Book::~Book() {}

void Book::setAuthor(const string& a) { author = a; }
void Book::setTitle(const string& t) { title = t; }
void Book::setPublisher(const string& p) { publisher = p; }
void Book::setYear(int y) { year = y; }
void Book::setPages(int pg) { pages = pg; }

string Book::getAuthor() const { return author; }
string Book::getTitle() const { return title; }
string Book::getPublisher() const { return publisher; }
int Book::getYear() const { return year; }
int Book::getPages() const { return pages; }

void Book::show() const {
    cout << "Автор: " << author << "\n"
         << "Название: " << title << "\n"
         << "Издательство: " << publisher << "\n"
         << "Год: " << year << "\n"
         << "Страниц: " << pages << "\n"
         << "------------------------\n";
}
