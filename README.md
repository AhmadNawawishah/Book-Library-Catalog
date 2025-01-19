# Book Library Catalog

This project is a simple Book Library Catalog written in C++. It allows users to add and remove books, search for books by title or author, track the borrowed status of books, and generate reading statistics.

## Features

- **Add and Remove Books**: Easily add new books to the library or remove existing ones.
- **Search by Title/Author**: Find books in the library by their title or author.
- **Track Borrowed Status**: Borrow and return books, and track which books are currently borrowed.
- **Generate Reading Statistics**: Get statistics on the total number of books and the number of borrowed books.

## Key Concepts

- **Objects for Book Data**: Using the `Book` class to represent each book.
- **Loops for Searching**: Using loops to search for books by title or author.
- **Functions for Statistics**: Functions to generate statistics about the library.

## Getting Started

### Prerequisites

To compile and run this project, you need a C++ compiler installed on your system.

### Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/book-library-catalog.git
    ```

2. **Navigate to the project directory**:
    ```bash
    cd book-library-catalog
    ```

3. **Compile the code**:
    ```bash
    g++ -o library_catalog library_catalog.cpp
    ```

4. **Run the executable**:
    ```bash
    ./library_catalog
    ```

## Usage

The project can be used to manage a library catalog through the command line interface. Here are some example commands:

```cpp
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
