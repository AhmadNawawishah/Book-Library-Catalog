#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;
    bool is_borrowed;

    Book(std::string t, std::string a) : title(t), author(a), is_borrowed(false) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void add_book(const std::string& title, const std::string& author) {
        books.push_back(Book(title, author));
    }

    void remove_book(const std::string& title) {
        books.erase(std::remove_if(books.begin(), books.end(), 
                   [&](const Book& book) { return book.title == title; }), books.end());
    }

    std::vector<Book> search_by_title(const std::string& title) {
        std::vector<Book> result;
        for (const auto& book : books) {
            if (book.title.find(title) != std::string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::vector<Book> search_by_author(const std::string& author) {
        std::vector<Book> result;
        for (const auto& book : books) {
            if (book.author.find(author) != std::string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::string borrow_book(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && !book.is_borrowed) {
                book.is_borrowed = true;
                return "You have borrowed '" + title + "'";
            }
        }
        return "'" + title + "' is not available.";
    }

    std::string return_book(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title && book.is_borrowed) {
                book.is_borrowed = false;
                return "You have returned '" + title + "'";
            }
        }
        return "'" + title + "' was not borrowed.";
    }

    int total_books() {
        return books.size();
    }

    int borrowed_books() {
        return std::count_if(books.begin(), books.end(), [](const Book& book) { return book.is_borrowed; });
    }
};

int main() {
    Library library;

    // Add books
    library.add_book("The Catcher in the Rye", "J.D. Salinger");
    library.add_book("To Kill a Mockingbird", "Harper Lee");

    // Search for a book by title
    std::vector<Book> found_books = library.search_by_title("Mockingbird");
    for (const auto& book : found_books) {
        std::cout << "Found: " << book.title << " by " << book.author << std::endl;
    }

    // Borrow and return books
    std::cout << library.borrow_book("To Kill a Mockingbird") << std::endl;
    std::cout << library.return_book("To Kill a Mockingbird") << std::endl;

    // Generate statistics
    std::cout << "Total books: " << library.total_books() << std::endl;
    std::cout << "Borrowed books: " << library.borrowed_books() << std::endl;

    return 0;
}

