#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
using namespace std;


struct BooksNode{
    string title;
    string author;
    string description;
    string review;
    int quantity;
    int price;
    BooksNode *parent;
    BooksNode *left = NULL;
    BooksNode *right= NULL;

    BooksNode(){};

    BooksNode(int in_quantity, string in_title, string in_author, int in_price, string in_descr, string in_review)
    {
        description = in_descr;
        author = in_author;
        review = in_review;
        title = in_title;
        quantity = in_quantity;
        price = in_price;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

struct Cart{

    Cart * BooksNode;
    Cart * next;
    string name;
    string author;
    string description;
    string review;
    int price;
    int quantity;

    Cart(){}; // default constructor

    Cart(string initName, Cart *initNext, int initPrice, string initAuthor)
    {
        name = initName;
        next = initNext;
        price = initPrice;
        author = initAuthor;
    }
};

class Books
{
    public:
        Books();
        ~Books();
        void createBookTree(Books & b, char const*  fileName);
        void addBooksNode(int quantity, string title, string author, int price, string description, string review);
        void printBookInventory(); //prints entire library
        int countBooksNodes(); //conts books in the entire file
        void deleteBooksNode(string title); //from cart
        void findMovie(string title); //buy option here
        void buyBooks(string title); //receipt, gives total and list of books with their prices
        int calculatePrice(BooksNode * Node);
        void viewCart();
        void addBook(string name);
        void cartDelete(string title);
        void insertReview(string title);
        void addToCart(BooksNode * node);
        void checkout(); //will call print cart here as well and ask questions etc.
        ///function to write reviews
        ///Make your own booklist! :D
    protected:

    private:
        void DeleteAll(BooksNode * node); //use this for the post-order traversal deletion of the tree
        void printBookInventory(BooksNode * node);
        void countBookNodes(BooksNode *node, int *c);
        BooksNode* search(string title);
        BooksNode* treeMinimum(BooksNode *node);
        BooksNode *root = NULL;
        Cart *head = NULL;
        Cart *tail = NULL;
};

#endif // MOVIETREE_H

