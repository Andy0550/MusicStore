//
//  class.h
//  MusicStore
//
//  Created by Michael Dvořák on 12/05/2019.
//  Copyright © 2019 Michael Dvořák. All rights reserved.
//

#ifndef class_h
#define class_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


//Item

class Item {
    
protected:
    
    int ID;
    string Name;
    string Type;
    string Info;
    string Genre;
    int ReleaseYear;
    int StoreDate;
    double Price;
    int InStock;
    
    
public:
    
    
    Item();
    
    Item(int, string, string, string, int, string, int, double, int);
    
    static int Count;
    
    int getID() const;
    
    string getName() const;
    
    string getType() const;
    
    string getInfo() const;
    
    int getStock() const;
    
    virtual string getAuthor() const = 0;
    
    virtual string getGenre() const;
    
    int getDate() const;
    
    int getYear() const;
    
    double getPrice() const;
    
    virtual void get() const = 0;
    
    virtual int getPages() const;
    
    void setName(string name);
    
    void setType(string type);
    
    void setInfo(string info);
    
    void setStock(int stock);
    
    void setYear(int year);
    
    void setStore(int store);
    
    void setPrice(double price);
    
    virtual void setPages(int pages);
    
    virtual void setAuthor(string author);
    
    virtual void setGenre(string genre);
    
    virtual void setDirector(string director);
    
    virtual void setArtist(string artist);
};



//Book

class Book : public Item {
    
private:
    int Pages;
    string Author;
    
public:
    Book(int, string, string, string, int, int, string, int, double, int);
    
    string getAuthor() const;
    
    int getPages() const;
    
    void get() const;
    
    void setPages(int pages);
    
    void setAuthor(string author);
};

//Movie

class Movie : public Item {
    
private:
    string Director;
    
public:
    Movie(int, string, string, string, int, string, string, int, double, int);
    
    string getAuthor() const;
    
    string getGenre() const;
    
    void get() const;
    
    void setDirector(string director);
    
    void setGenre(string genre);
    
};

//Vinyl

class Vinyl : public Item {
    
private:
    string Artist;
    
public:
    Vinyl (int, string, string, string, int, string, string, int, double, int);
    
    string getAuthor() const;
    
    string getGenre() const;
    
    void get() const;
    
    void setGenre(string genre);
    
    void setArtist(string artist);
};


//Person

class Person {

private:
    string Name;
    string Surname;
    string Address;
    string Email;

public:
    Person(string, string, string, string);
    
    string getName();
    
    string getSurname();
    
    string getAddress();
    
    string getEmail();
    
};

//Order

class Order {
    
private:
    int OrderID;
    string OrderDate;
    double Price;
    string ItemName;
    string Type;
    int Quantity;

public:
    Order(int,string,double,string,string,int);
    
    int getID();
    
    string getDate();
    
    double getPrice();
    
    string getItemName();
    
    string getType();
    
    int getQuant();
    
};


#endif /* class_h */
