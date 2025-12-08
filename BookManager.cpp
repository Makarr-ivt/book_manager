#include "BookManager.h"
#include <iostream>
#include <limits> // для numeric_limits<streamsize>::max()
#include <cstdlib>  // для system("cls")
#include <string>

using namespace std;

void BookManager::clearInput() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Пауза с ожиданием нажатия клавиши и очистка экрана
void BookManager::pauseAndClear() const {
    cout << "\nНажмите Enter для продолжения...";
    clearInput();
    system("cls");
}

// ввод целого числа с проверкой
int BookManager::inputInt(const string& prompt, int min, int max) const {
    int value;
    bool isValid = false;

    do {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                isValid = true;
            } else {
                cout << "Ошибка: число должно быть в диапазоне от "
                          << min << " до " << max << "!\n";
            }
        } else {
            cout << "Ошибка: введите корректное целое число!\n";
        }
        clearInput();
    } while (!isValid);

    return value;
}

void BookManager::addBook() {
    string author, title, publisher;
    int year, pages;

    cout << "Введите автора: ";
    getline(cin, author);

    cout << "Введите название: ";
    getline(cin, title);

    cout << "Введите издательство: ";
    getline(cin, publisher);

    year = inputInt("Введите год издания: ", 0, 3000);

    pages = inputInt("Введите количество страниц: ", 1, 10000);

    books.emplace_back(author, title, publisher, year, pages);
    cout << "\nКнига добавлена успешно!\n";
}

void BookManager::deleteBook() {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        pauseAndClear();
        return;
    }

    showAllBooks();
    int index = inputInt("\nВведите номер книги для удаления (1-" +
                             to_string(books.size()) + "): ",
                         1, books.size());

    books.erase(books.begin() + index - 1);
    cout << "Книга удалена успешно!\n";
}

void BookManager::editBook() {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        pauseAndClear();
        return;
    }

    showAllBooks();
    int index = inputInt("\nВведите номер книги для редактирования (1-" +
                             to_string(books.size()) + "): ",
                         1, books.size());

    Book& book = books[index - 1];
    int choice;

    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ КНИГИ ===\n";
        cout << "Текущая информация о книге:\n";
        book.show();

        cout << "\nЧто вы хотите изменить?\n"
                  << "1. Автора\n"
                  << "2. Название\n"
                  << "3. Издательство\n"
                  << "4. Год издания\n"
                  << "5. Количество страниц\n"
                  << "6. Вернуться в меню\n"
                  << "Выберите опцию: ";
        cin >> choice;
        clearInput();

        string strValue;
        int intValue;

        switch (choice) {
        case 1:
            cout << "Текущий автор: " << book.getAuthor() << "\n";
            cout << "Введите нового автора: ";
            getline(cin, strValue);
            book.setAuthor(strValue);
            cout << "Автор изменен успешно!\n";
            break;
        case 2:
            cout << "Текущее название: " << book.getTitle() << "\n";
            cout << "Введите новое название: ";
            getline(cin, strValue);
            book.setTitle(strValue);
            cout << "Название изменено успешно!\n";
            break;
        case 3:
            cout << "Текущее издательство: " << book.getPublisher() << "\n";
            cout << "Введите новое издательство: ";
            getline(cin, strValue);
            book.setPublisher(strValue);
            cout << "Издательство изменено успешно!\n";
            break;
        case 4:
            cout << "Текущий год издания: " << book.getYear() << "\n";
            intValue = inputInt("Введите новый год издания: ", 0, 3000);
            book.setYear(intValue);
            cout << "Год изменен успешно!\n";
            break;
        case 5:
            cout << "Текущее количество страниц: " << book.getPages() << "\n";
            intValue = inputInt("Введите новое количество страниц: ", 1, 10000);
            cout << "Количество страниц изменено успешно!\n";
            break;
        case 6:
            return;
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
        pauseAndClear();
    } while (choice != 6);
}

void BookManager::showAllBooks() const {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        return;
    }

    cout << "\n=== СПИСОК ВСЕХ КНИГ ===\n";
    cout << "Всего книг: " << books.size() << "\n\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "Книга #" << i + 1 << ":\n";
        books[i].show();
    }
}

void BookManager::showBooksByAuthor() const {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        return;
    }

    string author;
    cout << "Введите автора для поиска: ";
    getline(cin, author);

    cout << "\n=== КНИГИ АВТОРА: " << author << " ===\n";
    int count = 0;

    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            book.show();
            count++;
        }
    }

    if (!count) {
        cout << "Книги данного автора не найдены.\n";
    } else {
        cout << "Найдено книг: " << count << "\n";
    }
}

void BookManager::showBooksByPages() const {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        return;
    }

   int maxPages = inputInt("Введите максимальное количество страниц: ", 1, 10000);

    if (maxPages <= 0) {
        cout << "Неверное количество страниц!\n";
        return;
    }

    cout << "\n=== КНИГИ С КОЛИЧЕСТВОМ СТРАНИЦ МЕНЕЕ " << maxPages << " ===\n";
    int count = 0;

    for (const auto& book : books) {
        if (book.getPages() < maxPages) {
            book.show();
            count++;
        }
    }

    if (!count) {
        cout << "Книги с указанным количеством страниц не найдены.\n";
    } else {
        cout << "Найдено книг: " << count << "\n";
    }
}

void BookManager::showBooksAfterYear() const {
    if (books.empty()) {
        cout << "Список книг пуст!\n";
        return;
    }

    int minYear;
    cout << "Введите минимальный год издания: ";
    cin >> minYear;
    clearInput();

    cout << "\n=== КНИГИ, ИЗДАННЫЕ ПОСЛЕ " << minYear << " ГОДА ===\n";
    int count = 0;

    for (const auto& book : books) {
        if (book.getYear() > minYear) {
            book.show();
            count++;
        }
    }

    if (!count) {
        cout << "Книги, изданные после указанного года, не найдены.\n";
    } else {
        cout << "Найдено книг: " << count << "\n";
    }
}

void BookManager::run() {
    int choice;

    do {
        cout << "\n=== МЕНЕДЖЕР КНИГ ===\n"
                  << "1. Добавить книгу\n"
                  << "2. Удалить книгу\n"
                  << "3. Редактировать книгу\n"
                  << "4. Показать все книги\n"
                  << "5. Найти книги по автору\n"
                  << "6. Найти книги по количеству страниц\n"
                  << "7. Найти книги по году издания\n"
                  << "8. Выход\n"
                  << "========================\n"
                  << "Выберите опцию (1-8): ";

        choice = inputInt("Выберите опцию (1-8): ", 1, 8);

        switch (choice) {
        case 1:
            addBook();
            pauseAndClear();
            break;
        case 2:
            deleteBook();
            pauseAndClear();
            break;
        case 3:
            editBook();
            pauseAndClear();
            break;
        case 4:
            showAllBooks();
            pauseAndClear();
            break;
        case 5:
            showBooksByAuthor();
            pauseAndClear();
            break;
        case 6:
            showBooksByPages();
            pauseAndClear();
            break;
        case 7:
            showBooksAfterYear();
            pauseAndClear();
            break;
        case 8:
            cout << "\nВыход из программы...\n";
            break;
        }
    } while (choice != 8);
}
