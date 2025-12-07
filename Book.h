#pragma once
#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    Book();
    Book(const string& a, const string& t, const string& p, int y, int pg);
    Book(const Book& other);
    
    ~Book();

    void setAuthor(const string& a);
    void setTitle(const string& t);
    void setPublisher(const string& p);
    void setYear(int y);
    void setPages(int pg);

    string getAuthor() const;
    string getTitle() const;
    string getPublisher() const;
    int getYear() const;
    int getPages() const;

    void show() const;
};
