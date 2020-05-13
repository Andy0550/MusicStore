//
//  main.cpp
//  MusicStore
//
//  Created by Michael Dvořák on 12/05/2019.
//  Copyright © 2019 Michael Dvořák. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "class.h"
using namespace std;

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

//Function declarations

void printVec(vector<Item *>& List);

void readList(vector<Item *>& List);

void addData(Item& i);

void writeList(vector<Item *>& List);

void removeData(int id);

void editData(Item& i);

void createOrder(Person& p,double price,vector<pair<int,int>>& v);

void readOrders();

void changeStock(int ID, int Stock);


//Main

int main(int argc, const char * argv[]) {
    
    vector<Item *> List;
    
    cout << "...Welcome to the BEST E-Shop app..." << endl;
    cout << "______________________________________" << endl <<  endl;
    
    readList(List);
    
    bool run = true;
    
    while (run == true) {
        cout << "Please, choose a required action:" << endl << endl;
        cout << "0) OPEN ITEMS LIST" << endl;
        cout << "1) ADD ITEMS " << endl;
        cout << "2) REMOVE ITEMS " << endl;
        cout << "3) SEARCH " << endl;
        cout << "4) EDIT ITEMS " << endl;
        cout << "5) CREATE ORDER" << endl;
        cout << "6) SHOW ORDERS" << endl;
        cout << "7) EXIT" << endl << endl;
        
        int i = 0;
        cin >> i;
        if (cin.fail()) {
            cout << "Input only numbers!!!" << endl;
            break;
        }
        
        switch (i) {
            case 0:
                printVec(List);
                break;
                
            case 1: {
                cout << "Choose type of item: " << endl;
                cout << "1) Book" << endl;
                cout << "2) Movie" << endl;
                cout << "3) Vinyl" << endl;
                int x = 0;
                cin >> x;
                
                string Name,Type,Info,Author,Genre;
                int Pages,ReleaseYear,StoreYear,InStock;
                double Price;
                
                switch (x) {
                    case 1: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter count of pages: ";
                        cin >> Pages;
                        cin.ignore();
                        cout << "Enter author: ";
                        getline(cin,Author);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        cout << "Enter price($): ";
                        cin >> Price;
                        cin.ignore();
                        cout << "Enter how many items are in stock: ";
                        cin >> InStock;
                        cin.ignore();
                        List.push_back (new Book (Item::Count, Name, Type, Info, ReleaseYear, Pages, Author, StoreYear, Price, InStock));
                        break;
                    }
                    case 2: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter director: ";
                        getline(cin,Author);
                        cout << "Enter genre: ";
                        getline(cin,Genre);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        cout << "Enter price($): ";
                        cin >> Price;
                        cin.ignore();
                        cout << "Enter how many items are in stock: ";
                        cin >> InStock;
                        cin.ignore();
                        List.push_back (new Movie (Item::Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear, Price, InStock));
                        break;
                    }
                    case 3: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter artist: ";
                        getline(cin,Author);
                        cout << "Enter genre: ";
                        getline(cin,Genre);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        cout << "Enter price($): ";
                        cin >> Price;
                        cin.ignore();
                        cout << "Enter how many items are in stock: ";
                        cin >> InStock;
                        cin.ignore();
                        List.push_back (new Movie (Item::Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear, Price, InStock));
                        break;
                    }
                    default:
                        break;
                }
                addData(*List[List.size()-1]);
                break;
            }
                
            case 2:
                printVec(List);
                cout << "Enter item's ID: " << endl;
                cin >> i;
                for (int c = 0; c < List.size(); c++) {
                    if((List[c] -> getID()) == i) {
                        List.erase(List.begin() + c);
                    }
                }
                printVec(List);
                removeData(i);
                break;
                
            case 3: {
                cout << "Enter item's ID/name: ";
                string i;
                cin >> i;
                for (int c = 0; c < List.size(); c++) {
                    if((List[c] -> getID()) == stoi(i) || (List[c] -> getName()) == i) {
                        List[c] -> get();
                    }
                }
                break;
            }
                
            case 4: {
                cin.ignore();
                printVec(List);
                cout << "Enter item's ID/name: ";
                string i;
                
                cin >> i;
                for (int c = 0; c < List.size(); c++) {
                    if((List[c] -> getID()) == stoi(i) || (List[c] -> getName()) == i) {
                        List[c] -> get();
                        cout << "Select information you want to edit: " << endl;
                        if(List[c] -> getType() == "Book") {
                            cout << "1) Name" << endl;
                            cout << "2) Type" << endl;
                            cout << "3) Info" << endl;
                            cout << "4) Release Year" << endl;
                            cout << "5) Count of pages" << endl;
                            cout << "6) Author" << endl;
                            cout << "7) Year of store" << endl;
                            cout << "8) Price($)" << endl;
                            cout << "9) Items in Stock" << endl;
                            int x;
                            string h;
                            cin >> x;
                            switch (x) {
                                case 1:
                                    cout << "Enter NEW Name: " << endl;
                                    cin >> h;
                                    List[c] -> setName(h);
                                    break;
                                case 2:
                                    cout << "Enter NEW Type: " << endl;
                                    cin >> h;
                                    List[c] -> setType(h);
                                    break;
                                case 3:
                                    cout << "Enter NEW Info: " << endl;
                                    cin >> h;
                                    List[c] -> setInfo(h);
                                    break;
                                case 4:
                                    cout << "Enter NEW Release Year: " << endl;
                                    cin >> h;
                                    List[c] -> setYear(stoi(h));
                                    break;
                                case 5:
                                    cout << "Enter NEW Count of pages: " << endl;
                                    cin >> h;
                                    List[c] -> setPages(stoi(h));
                                    break;
                                case 6:
                                    cout << "Enter NEW Author: " << endl;
                                    cin >> h;
                                    List[c] -> setAuthor(h);
                                    break;
                                case 7:
                                    cout << "Enter NEW Store Year : " << endl;
                                    cin >> h;
                                    List[c] -> setStore(stoi(h));
                                    break;
                                case 8:
                                    cout << "Enter NEW Price($): " << endl;
                                    cin >> h;
                                    List[c] -> setPrice(stod(h));
                                case 9:
                                    cout << "Enter NEW number of items in stock: " << endl;
                                    cin >> h;
                                    List[c] -> setStock(stoi(h));
                                default:
                                    break;
                            }
                        }
                        else if (List[c] -> getType() == "Movie") {
                            cout << "1) Name" << endl;
                            cout << "2) Type" << endl;
                            cout << "3) Info" << endl;
                            cout << "4) Release Year" << endl;
                            cout << "5) Director" << endl;
                            cout << "6) Genre" << endl;
                            cout << "7) Year of store" << endl;
                            cout << "8) Price($)" << endl;
                            cout << "9) Items in Stock" << endl;
                            int x;
                            string h;
                            cin >> x;
                            switch (x) {
                                case 1:
                                    cout << "Enter NEW Name: " << endl;
                                    cin >> h;
                                    List[c] -> setName(h);
                                    break;
                                case 2:
                                    cout << "Enter NEW Type: " << endl;
                                    cin >> h;
                                    List[c] -> setType(h);
                                    break;
                                case 3:
                                    cout << "Enter NEW Info: " << endl;
                                    cin >> h;
                                    List[c] -> setInfo(h);
                                    break;
                                case 4:
                                    cout << "Enter NEW Release Year: " << endl;
                                    cin >> h;
                                    List[c] -> setYear(stoi(h));
                                    break;
                                case 5:
                                    cout << "Enter NEW Director: " << endl;
                                    cin >> h;
                                    List[c] -> setDirector(h);
                                    break;
                                case 6:
                                    cout << "Enter NEW Genre: " << endl;
                                    cin >> h;
                                    List[c] -> setGenre(h);
                                    break;
                                case 7:
                                    cout << "Enter NEW Store Year : " << endl;
                                    cin >> h;
                                    List[c] -> setStore(stoi(h));
                                    break;
                                case 8:
                                    cout << "Enter NEW Price($): " << endl;
                                    cin >> h;
                                    List[c] -> setPrice(stod(h));
                                case 9:
                                    cout << "Enter NEW number of items in stock: " << endl;
                                    cin >> h;
                                    List[c] -> setStock(stoi(h));
                                default:
                                    break;
                            }
                        }
                        else if (List[c] -> getType() == "Vinyl") {
                            cout << "1) Name" << endl;
                            cout << "2) Type" << endl;
                            cout << "3) Info" << endl;
                            cout << "4) Release Year" << endl;
                            cout << "5) Artist" << endl;
                            cout << "6) Genre" << endl;
                            cout << "7) Year of store" << endl;
                            cout << "8) Price($)" << endl;
                            cout << "9) Items in Stock" << endl;
                            int x;
                            string h;
                            cin >> x;
                            switch (x) {
                                case 1:
                                    cout << "Enter NEW Name: " << endl;
                                    cin >> h;
                                    List[c] -> setName(h);
                                    break;
                                case 2:
                                    cout << "Enter NEW Type: " << endl;
                                    cin >> h;
                                    List[c] -> setType(h);
                                    break;
                                case 3:
                                    cout << "Enter NEW Info: " << endl;
                                    cin >> h;
                                    List[c] -> setInfo(h);
                                    break;
                                case 4:
                                    cout << "Enter NEW Release Year: " << endl;
                                    cin >> h;
                                    List[c] -> setYear(stoi(h));
                                    break;
                                case 5:
                                    cout << "Enter NEW Artist: " << endl;
                                    cin >> h;
                                    List[c] -> setArtist(h);
                                    break;
                                case 6:
                                    cout << "Enter NEW Genre: " << endl;
                                    cin >> h;
                                    List[c] -> setGenre(h);
                                    break;
                                case 7:
                                    cout << "Enter NEW Store Year : " << endl;
                                    cin >> h;
                                    List[c] -> setStore(stoi(h));
                                    break;
                                case 8:
                                    cout << "Enter NEW Price($): " << endl;
                                    cin >> h;
                                    List[c] -> setPrice(stod(h));
                                case 9:
                                    cout << "Enter NEW number of items in stock: " << endl;
                                    cin >> h;
                                    List[c] -> setStock(stoi(h));
                                default:
                                    break;
                            }
                        }
                    }
                    editData(*List[c]);
                }
                break;
            }
                
            case 5: {
                string N,S,A,E;
                cin.ignore();
                cout << "Enter your name: ";
                cin >> N;
                cin.ignore();
                cout << "Enter your surname: ";
                cin >> S;
                cin.ignore();
                cout << "Enter your address: ";
                getline(cin,A);
                cout << "Enter your email: ";
                getline(cin,E);
                Person user(N,S,A,E);
                
                bool o = true;
                double price = 0;
                vector<pair <int,int> > vct;
                
                while(o == true) {
                    printVec(List);
                    int c,q;
                    cout << "Enter item's ID: ";
                    cin >> c;
                    cout << endl;
                    List[c-1]->get();
                    cout << "How many do you want to buy?" << endl;
                    cin >> q;
                    if(q > List[c-1]->getStock()) {
                        cout << "Not enough items in stock!!!" << endl << endl;
                        continue;
                    }
                    price += (List[c-1]->getPrice() * q);
                    vct.push_back(make_pair(c,q));
                    List[c-1]->setStock(List[c-1]->getStock()-q);
                    changeStock(c, (List[c-1]->getStock()-q));
                    
                    string p;
                    cout << "Do you want to buy something else? (Y/N)" << endl;
                    cin >> p;
                    if(p == "Y") {
                        continue;
                    }
                    else if(p == "N") {
                        createOrder(user,price,vct);
                        cout << "Order Completed!!!" << endl;
                        cout << "Final Price: " << price << endl;
                        cout << "You'll find more instructions in your email" << endl;
                        o = false;
                    }
                    else {
                        cout << "Wrong Answer!" << endl;
                        break;
                    }
                }
                break;
            }
                
            case 6:
                readOrders();
                break;
                
                
            case 7:
                cout << "Shutting down..." << endl << endl;
                run = false;
                break;
                
            default:
                cout << "Wrong choice!!! Please try again. " << endl << endl;
                break;
                
        }
        
    }
    
    return 0;
}


//Function definitions


void printVec(vector<Item *>& List) {
    for (int c = 0; c < List.size(); c++) {
        List[c] -> get();
    }
}

void readList(vector<Item *>& List) {
    int id = 0, date = 0, pages = 0, store = 0, stock = 0;
    string name, type, info, author, genre;
    double price;
    
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM Items");
        while (res->next()) {
            id = res->getInt(1);
            name = res->getString(2);
            type = res->getString(3);
            info = res->getString(4);
            date = res->getInt(5);
            if (res->getString(3) == "Book") {
                author = res->getString(6);
                pages = res->getInt(9);
            }
            else if (res->getString(3) == "Movie") {
                author = res->getString(8);
                genre = res->getString(10);
            }
            else if (res->getString(3) == "Vinyl") {
                author = res->getString(7);
                genre = res->getString(10);
            }
            store = res->getInt(11);
            price = res->getDouble(12);
            stock= res->getInt(13);
            
            try {
                if(type == "Book") {
                    List.push_back (new Book (id, name, type, info, date, pages, author, store, price, stock));
                }
                else if (type == "Movie") {
                    List.push_back (new Movie (id, name, type, info, date, author, genre, store, price, stock));
                }
                else if (type == "Vinyl") {
                    List.push_back (new Vinyl (id, name, type, info, date, author, genre, store, price, stock));
                }
            } catch (invalid_argument) {
                continue;
            }
        }
        
        delete res;
        delete stmt;
        delete con;
        
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    
    
}


void addData(Item& i) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt = NULL;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        if(i.getType() == "Book") {
            pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Author,Pages,StoreDate,Price,InStock) VALUES (?,?,?,?,?,?,?,?,?,?)");
            pstmt->setInt(1, i.getID());
            pstmt->setString(2, i.getName());
            pstmt->setString(3, i.getType());
            pstmt->setString(4, i.getInfo());
            pstmt->setInt(5, i.getYear());
            pstmt->setString(6, i.getAuthor());
            pstmt->setInt(7, i.getPages());
            pstmt->setInt(8, i.getDate());
            pstmt->setDouble(9, i.getPrice());
            pstmt->setInt(10, i.getStock());
            pstmt->executeUpdate();
        }
        else if(i.getType() == "Movie") {
            pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Director,Genre,StoreDate,Price,InStock) VALUES (?,?,?,?,?,?,?,?,?,?)");
            pstmt->setInt(1, i.getID());
            pstmt->setString(2, i.getName());
            pstmt->setString(3, i.getType());
            pstmt->setString(4, i.getInfo());
            pstmt->setInt(5, i.getYear());
            pstmt->setString(6, i.getAuthor());
            pstmt->setString(7, i.getGenre());
            pstmt->setInt(8, i.getDate());
            pstmt->setDouble(9, i.getPrice());
            pstmt->setInt(10, i.getStock());
            pstmt->executeUpdate();
        }
        else if(i.getType() == "Vinyl") {
            pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Artist,Genre,StoreDate,Price,InStock) VALUES (?,?,?,?,?,?,?,?,?,?)");
            pstmt->setInt(1, i.getID());
            pstmt->setString(2, i.getName());
            pstmt->setString(3, i.getType());
            pstmt->setString(4, i.getInfo());
            pstmt->setInt(5, i.getYear());
            pstmt->setString(6, i.getAuthor());
            pstmt->setString(7, i.getGenre());
            pstmt->setInt(8, i.getDate());
            pstmt->setDouble(9, i.getPrice());
            pstmt->setInt(10, i.getStock());
            pstmt->executeUpdate();
        }
        
        delete pstmt;
        delete con;
        
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}


void removeData(int id) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt = NULL;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        pstmt = con->prepareStatement("DELETE FROM Items WHERE ID = ?");
        pstmt->setInt(1, id);
        pstmt->executeQuery();
        
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void editData(Item& i) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt = NULL;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        if(i.getType() == "Book") {
            pstmt = con->prepareStatement("UPDATE Items SET Name = ?, Type = ?, Info = ?, ReleaseYear = ?, Author = ?, Pages = ?, StoreDate = ?, Price = ?, InStock = ? WHERE ID = ?");
            pstmt->setString(1, i.getName());
            pstmt->setString(2, i.getType());
            pstmt->setString(3, i.getInfo());
            pstmt->setInt(4, i.getYear());
            pstmt->setString(5, i.getAuthor());
            pstmt->setInt(6, i.getPages());
            pstmt->setInt(7, i.getDate());
            pstmt->setDouble(8, i.getPrice());
            pstmt->setInt(9, i.getStock());
            pstmt->setInt(10, i.getID());
            pstmt->executeUpdate();
        }
        else if(i.getType() == "Movie") {
            pstmt = con->prepareStatement ("UPDATE Items SET Name = ?, Type = ?, Info = ?, ReleaseYear = ?, Director = ?, Genre = ?, StoreDate = ?, Price = ?, InStock = ? WHERE ID = ?");
            pstmt->setString(1, i.getName());
            pstmt->setString(2, i.getType());
            pstmt->setString(3, i.getInfo());
            pstmt->setInt(4, i.getYear());
            pstmt->setString(5, i.getAuthor());
            pstmt->setString(6, i.getGenre());
            pstmt->setInt(7, i.getDate());
            pstmt->setDouble(8, i.getPrice());
            pstmt->setInt(9, i.getStock());
            pstmt->setInt(10, i.getID());
            pstmt->executeUpdate();
        }
        else if(i.getType() == "Vinyl") {
            pstmt = con->prepareStatement("UPDATE Items SET Name = ?, Type = ?, Info = ?, ReleaseYear = ?, Artist = ?, Genre = ?, StoreDate = ?, Price = ?, InStock = ? WHERE ID = ?");
            pstmt->setString(1, i.getName());
            pstmt->setString(2, i.getType());
            pstmt->setString(3, i.getInfo());
            pstmt->setInt(4, i.getYear());
            pstmt->setString(5, i.getAuthor());
            pstmt->setString(6, i.getGenre());
            pstmt->setInt(7, i.getDate());
            pstmt->setDouble(8, i.getPrice());
            pstmt->setInt(9, i.getStock());
            pstmt->setInt(10, i.getID());
            pstmt->executeUpdate();
        }
        pstmt->executeQuery();
        
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void createOrder(Person& p, double price, vector<pair<int,int>>& v) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt = NULL;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        pstmt = con->prepareStatement("INSERT IGNORE INTO Customers(Name,Surname,Address,Email) VALUES (?,?,?,?)");
        pstmt->setString(1, p.getName());
        pstmt->setString(2, p.getSurname());
        pstmt->setString(3, p.getAddress());
        pstmt->setString(4, p.getEmail());
        pstmt->executeUpdate();
        
        pstmt = con->prepareStatement("INSERT IGNORE INTO Orders(OrderDate,CustomerID,Price) VALUES((SELECT CURDATE()),(SELECT Customers.ID FROM CUSTOMERS WHERE Name = ? AND Customers.SURNAME = ?),?)");
        pstmt->setString(1, p.getName());
        pstmt->setString(2, p.getSurname());
        pstmt->setDouble(3, price);
        pstmt->executeUpdate();
    
        
        for(int c  = 0; c < v.size(); c++) {
            pstmt = con->prepareStatement("INSERT INTO OrdersItems(ItemID,OrderID,Quantity) VALUES (?,(SELECT MAX(ID) FROM ORDERS LIMIT 1),?)");
            pstmt->setInt(1, v[c].first);
            pstmt->setInt(2, v[c].second);
            pstmt->executeUpdate();
        }
    
        delete pstmt;
        delete con;
        
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void readOrders() {
    int OrderID, Quantity = 0;
    double Price = 0;
    string Date, Name, Surname, Email, Address, iName, Type;
    string q = "SELECT Orders.ID, Orders.OrderDate, Customers.Name, Customers.Surname, Customers.Address,Customers.Email, Orders.Price, Items.Name, Items.Type, OrdersItems.Quantity FROM Customers INNER JOIN Orders ON Customers.ID = Orders.CustomerID INNER JOIN OrdersItems ON Orders.ID = OrdersItems.OrderID INNER JOIN Items ON OrdersItems.ItemID = Items.ID ORDER BY OrdersItems.OrderID;";
    vector<pair<Person,Order>> Orders;

    
    try {
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
    /* Connect to the MySQL test database */
    con->setSchema("Store");
    stmt = con->createStatement();
    res = stmt->executeQuery(q);
    while (res->next()) {
        OrderID = res->getInt(1);
        Date = res->getString(2);
        Name = res->getString(3);
        Surname = res->getString(4);
        Address = res->getString(5);
        Email = res->getString(6);
        Price = res->getDouble(7);
        iName = res->getString(8);
        Type = res->getString(9);
        Quantity = res->getInt(10);
        
        Person p(Name,Surname,Address,Email);
        Order o(OrderID,Date,Price,iName,Type,Quantity);
        
        
        Orders.push_back(make_pair(p,o));
        
}
        int CurrOrd = 0;
        for(int c = 0; c < Orders.size();c++) {
            if(Orders[c].second.getID() == CurrOrd) {
                cout << "&" << endl << endl;
                cout << "Item name: " << Orders[c].second.getItemName() << endl;
                cout << "Item type: " << Orders[c].second.getType() << endl;
                cout << "Quantity: " << Orders[c].second.getQuant() << endl << endl;
            }
            else {
                cout << "Order number: " << Orders[c].second.getID() << endl;
                cout << "Order date: " << Orders[c].second.getDate() << endl;
                cout << "Final price: " << Orders[c].second.getPrice() << "$" << endl << endl;
                cout << "Customer name: " << Orders[c].first.getName() << " " << Orders[c].first.getSurname() << endl;
                cout << "Customer email: " << Orders[c].first.getEmail() << endl;
                cout << "Customer address: " << Orders[c].first.getAddress() << endl << endl;
                cout << "Item name: " << Orders[c].second.getItemName() << endl;
                cout << "Item type: " << Orders[c].second.getType() << endl;
                cout << "Quantity: " << Orders[c].second.getQuant() << endl << endl;
                CurrOrd = Orders[c].second.getID();
            }
        }
    
    delete res;
            delete stmt;
            delete con;
            
        } catch (sql::SQLException &e) {
            cout << "# ERR: SQLException in " << __FILE__;
            cout << "# ERR: " << e.what();
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
        
        
    }

void changeStock(int ID, int Stock) {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *pstmt = NULL;
        
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
        /* Connect to the MySQL test database */
        con->setSchema("Store");
        pstmt = con->prepareStatement("UPDATE Items SET InStock = ? WHERE ID = ?;");
        pstmt->setInt(1,Stock);
        pstmt->setInt(2,ID);
        pstmt->executeQuery();
        
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    }


/*
 cout << "...Welcome to Music Store System..." << endl;
 cout << "______________________________________" << endl <<  endl;
 cout << "Please, choose a required action:" << endl << endl;
 cout << "1) Create Order" << endl;
 cout << "2) Find Music" << endl;
 cout << "3) Sold Items" << endl;
 cout << "4) Items in Stock" << endl;
 cout << "5) All Items" << endl;
 cout << "6) Add New Item" << endl;
 cout << "7) Edit Item" << endl;
 cout << "8) Remove Item" << endl;
 cout << "9) Exit" << endl << endl;
 */


/*
 
 
 try {
 sql::Driver *driver;
 sql::Connection *con;
 sql::Statement *stmt;
 sql::ResultSet *res;
 
 
 driver = get_driver_instance();
 con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
 // Connect to the MySQL test database //
 con->setSchema("Store");
 stmt = con->createStatement();
 res = stmt->executeQuery("SELECT * FROM Items");
 while (res->next()) {
 cout << "ID = " << res->getInt(1) << endl;
 cout << "Name = " << res->getString(2) << endl;
 cout << "Type = " << res->getString(3) << endl;
 cout << "Info = " << res->getString(4) << endl;
 cout << "Release Year = " << res->getInt(5) << endl;
 if (res->getString(3) == "Book") {
 cout << "Author = " << res->getString(6) << endl;
 cout << "Pages = " << res->getInt(9) << endl;
 }
 else if (res->getString(3) == "Movie") {
 cout << "Director = " << res->getString(8) << endl;
 cout << "Genre = " << res->getString(10) << endl;
 }
 else if (res->getString(3) == "Vinyl") {
 cout << "Artist = " << res->getString(7) << endl;
 cout << "Genre = " << res->getString(10) << endl;
 }
 cout << "Store Date = " << res->getInt(11) << endl;
 cout << "______________________________________" << endl << endl;
 }
 
 delete res;
 delete stmt;
 delete con;
 
 } catch (sql::SQLException &e) {
 cout << "# ERR: SQLException in " << __FILE__;
 cout << "# ERR: " << e.what();
 cout << " (MySQL error code: " << e.getErrorCode();
 cout << ", SQLState: " << e.getSQLState() << " )" << endl;
 }
 
 
 cout << endl;
 

 void writeList(vector<Item *>& List) {
     try {
         sql::Driver *driver;
         sql::Connection *con;
         sql::PreparedStatement *pstmt = NULL;
         --------------
         driver = get_driver_instance();
         con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
         con->setSchema("Store");
         for (int c = 0; c < List.size(); c++) {
             if(List[c]->getType() == "Book") {
                 pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Author,Pages,StoreDate,Price) VALUES (?,?,?,?,?,?,?,?,?)");
                 pstmt->setInt(1, List[c]->getID());
                 pstmt->setString(2, List[c]->getName());
                 pstmt->setString(3, List[c]->getType());
                 pstmt->setString(4, List[c]->getInfo());
                 pstmt->setInt(5, List[c]->getYear());
                 pstmt->setString(6, List[c]->getAuthor());
                 pstmt->setInt(7, List[c]->getPages());
                 pstmt->setInt(8, List[c]->getDate());
                 pstmt->setDouble(9, List[c]->getPrice());
                 pstmt->executeUpdate();
             }
             else if(List[c]->getType() == "Movie") {
                 pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Director,Genre,StoreDate, Price) VALUES (?,?,?,?,?,?,?,?,?)");
                 pstmt->setInt(1, List[c]->getID());
                 pstmt->setString(2, List[c]->getName());
                 pstmt->setString(3, List[c]->getType());
                 pstmt->setString(4, List[c]->getInfo());
                 pstmt->setInt(5, List[c]->getYear());
                 pstmt->setString(6, List[c]->getAuthor());
                 pstmt->setString(7, List[c]->getGenre());
                 pstmt->setInt(8, List[c]->getDate());
                 pstmt->setDouble(9, List[c]->getPrice());
                 pstmt->executeUpdate();
             }
             else if(List[c]->getType() == "Vinyl") {
                 pstmt = con->prepareStatement("INSERT INTO Items(ID,Name,Type,Info,ReleaseYear,Artist,Genre,StoreDate, Price) VALUES (?,?,?,?,?,?,?,?,?)");
                 pstmt->setInt(1, List[c]->getID());
                 pstmt->setString(2, List[c]->getName());
                 pstmt->setString(3, List[c]->getType());
                 pstmt->setString(4, List[c]->getInfo());
                 pstmt->setInt(5, List[c]->getYear());
                 pstmt->setString(6, List[c]->getAuthor());
                 pstmt->setString(7, List[c]->getGenre());
                 pstmt->setInt(8, List[c]->getDate());
                 pstmt->setDouble(9, List[c]->getPrice());
                 pstmt->executeUpdate();
             }
         }
         
         delete pstmt;
         delete con;
         
     } catch (sql::SQLException &e) {
         cout << "# ERR: SQLException in " << __FILE__;
         cout << "# ERR: " << e.what();
         cout << " (MySQL error code: " << e.getErrorCode();
         cout << ", SQLState: " << e.getSQLState() << " )" << endl;
     }
 }
 
 void createOrder(Person& p, vector<pair<int,int>>& v) {
     try {
         sql::Driver *driver;
         sql::Connection *con;
         sql::PreparedStatement *pstmt = NULL;
         
         driver = get_driver_instance();
         con = driver->connect("tcp://127.0.0.1:3306", "root", "MyNewPass");
    ------------
         con->setSchema("Store");
         pstmt = con->prepareStatement("INSERT IGNORE INTO Customers(Name,Surname,Address,Email) VALUES (?,?,?,?)");
         pstmt->setString(1, p.getName());
         pstmt->setString(2, p.getSurname());
         pstmt->setString(3, p.getAddress());
         pstmt->setString(4, p.getEmail());
         pstmt->executeUpdate();
         
         pstmt = con->prepareStatement("INSERT IGNORE INTO Orders(OrderDate,CustomerID,Price) VALUES((SELECT CURDATE()),(SELECT Customers.ID FROM CUSTOMERS WHERE Name = ? AND Customers.SURNAME = ?),0)");
         pstmt->setString(1, p.getName());
         pstmt->setString(2, p.getSurname());
         pstmt->executeUpdate();
         
         pstmt = con->prepareStatement("INSERT INTO OrdersItems(ItemID,OrderID,Quantity) VALUES (?,(SELECT LAST_INSERT_ID() FROM ORDERS LIMIT 1),?)");
         pstmt->setInt(1, i.getID());
         pstmt->setInt(2, q);
         pstmt->executeUpdate();
         
         pstmt = con->prepareStatement("UPDATE Orders SET Price = (Price + (? * ?)) WHERE ID = (SELECT LAST_INSERT_ID() FROM (SELECT LAST_INSERT_ID() FROM ORDERS) AS T LIMIT 1)");
         pstmt->setDouble(1, i.getPrice());
         pstmt->setInt(2, q);
         pstmt->executeUpdate();
         
         
         delete pstmt;
         delete con;
         
     }
     catch (sql::SQLException &e) {
         cout << "# ERR: SQLException in " << __FILE__;
         cout << "# ERR: " << e.what();
         cout << " (MySQL error code: " << e.getErrorCode();
         cout << ", SQLState: " << e.getSQLState() << " )" << endl;
     }
 }

 
 
 
 
 */
