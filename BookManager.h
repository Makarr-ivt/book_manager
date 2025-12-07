#pragma once
#include "Book.h"
#include <vector>
#include <climits>  // Для INT_MIN и INT_MAX

class BookManager {
private:
    vector<Book> books;
    void clearInput() const;
    void pauseAndClear() const;
    int inputInt(const string& prompt, int min = INT_MIN, int max = INT_MAX) const;

public:
    void addBook();
    void deleteBook();
    void editBook();
    void showAllBooks() const;

    void showBooksByAuthor() const;
    void showBooksByPages() const;
    void showBooksAfterYear() const;

    void run();
};
