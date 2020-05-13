//
//  class.cpp
//  MusicStore
//
//  Created by Michael Dvořák on 12/05/2019.
//  Copyright © 2019 Michael Dvořák. All rights reserved.
//

#include <stdio.h>
#include "class.h"
#include <string>


Item::Item() {
    Name = "";
    Type = "";
    Info = "";
    Genre = "";
}

Item::Item(int ID, string Name, string Type, string Info, int ReleaseYear, string Genre, int StoreDate, double Price, int InStock) {
    this->ID = ID;
    this->Name = Name;
    this->Type = Type;
    this->Info = Info;
    this->ReleaseYear = ReleaseYear;
    this->Genre = Genre;
    this->StoreDate = StoreDate;
    this->Price = Price;
    this->InStock = InStock;
}


int Item::getID() const {
    return ID;
}

string Item::getName() const {
    return Name;
}

string Item::getType() const {
    return Type;
}

string Item::getInfo() const {
    return Info;
}

int Item::getStock() const {
    return InStock;
}

int Item::getYear() const {
    return ReleaseYear;
}

int Item::getDate() const {
    return StoreDate;
}

double Item::getPrice() const {
    return Price;
}

int Item::getPages() const {
    return 0;
};

string Item::getGenre() const {
    return "";
}

void Item::setName(string name) {
    Name = name;
}

void Item::setType(string type) {
    Type = type;
}

void Item::setInfo(string info) {
    Info = info;
}

void Item::setStock(int stock) {
    InStock = stock;
}

void Item::setYear(int year) {
    ReleaseYear = year;
}

void Item::setStore(int store) {
    StoreDate = store;
}

void Item::setPrice(double price) {
    Price = price;
}

void Item::setAuthor(string author) {};

void Item::setPages(int pages) {};

void Item::setDirector(string director) {};

void Item::setGenre(string genre) {};

void Item::setArtist(string artist) {};

int Item::Count = 1;

//Book

Book::Book(int ID, string Name, string Type, string Info, int ReleaseYear, int Pages, string Author, int StoreDate, double Price, int InStock) : Item(ID, Name, Type, Info, ReleaseYear, "", StoreDate, Price, InStock) {
    this->Pages = Pages;
    this->Author = Author;
    ID = Count++;
}

int Book::getPages() const {
    return Pages;
}

string Book::getAuthor() const {
    return Author;
}

void Book::get() const {
    cout << "ID: " << ID << endl;
    cout << "Name: " << Name << endl;
    cout << "Type: " << Type << endl;
    cout << "Info: " << Info << endl;
    cout << "Release Year: " << ReleaseYear << endl;
    cout << "Pages: " << Pages << endl;
    cout << "Author: " << Author << endl;
    cout << "Store Date: " << StoreDate << endl;
    cout << "Price($): " << Price << endl;
    cout << "In Stock: " << InStock << endl << endl;
}

void Book::setPages(int pages) {
    Pages = pages;
}

void Book::setAuthor(string author) {
    Author = author;
}

//Movie

Movie::Movie(int ID, string Name, string Type, string Info, int ReleaseYear, string Director, string Genre, int StoreDate, double Price, int InStock) : Item(ID, Name, Type, Info, ReleaseYear, Genre, StoreDate, Price, InStock) {
    
    this->Director = Director;
    ID = Count++;
}

string Movie::getAuthor() const {
    return Director;
}

string Movie::getGenre() const  {
    return Genre;
}

void Movie::get() const {
    cout << "ID: " << ID << endl;
    cout << "Name: " << Name << endl;
    cout << "Type: " << Type << endl;
    cout << "Info: " << Info << endl;
    cout << "Release Year: " << ReleaseYear << endl;
    cout << "Director: " << Director << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Store Date: " << StoreDate << endl;
    cout << "Price($): " << Price << endl;
    cout << "In Stock: " << InStock << endl << endl;
    
}

void Movie::setDirector(string director) {
    Director = director;
}

void Movie::setGenre(string genre) {
    Genre = genre;
}


//Vinyl

Vinyl::Vinyl(int ID, string Name, string Type, string Info, int ReleaseYear, string Artist, string Genre, int StoreDate, double Price, int InStock) : Item(ID, Name, Type, Info, ReleaseYear, Genre, StoreDate, Price, InStock) {
    
    this->Artist = Artist;
    ID = Count++;
}

string Vinyl::getAuthor() const {
    return Artist;
}

string Vinyl::getGenre() const {
    return Genre;
}

void Vinyl::get() const {
    cout << "ID: " << ID << endl;
    cout << "Name: " << Name << endl;
    cout << "Type: " << Type << endl;
    cout << "Info: " << Info << endl;
    cout << "Release Year: " << ReleaseYear << endl;
    cout << "Artist: " << Artist << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Store Date: " << StoreDate << endl;
    cout << "Price($): " << Price << endl;
    cout << "In Stock: " << InStock << endl << endl;
}

void Vinyl::setGenre(string genre) {
    Genre = genre;
}

void Vinyl::setArtist(string artist) {
    Artist = artist;
}


//Person

Person::Person(string Name, string Surname, string Address, string Email) {
    this -> Name = Name;
    this -> Surname = Surname;
    this -> Address = Address;
    this -> Email = Email;
}
               
string Person::getName() {
    return Name;
}
               
string Person::getSurname() {
    return Surname;
}
               
string Person::getAddress() {
    return Address;
}
               
string Person::getEmail() {
    return Email;
}



//Order

Order::Order(int OrderID,string OrderDate,double Price,string ItemName, string Type, int Quantity) {
    this -> OrderID = OrderID;
    this -> OrderDate = OrderDate;
    this -> Price = Price;
    this -> ItemName = ItemName;
    this -> Type = Type;
    this -> Quantity = Quantity;
}

int Order::getID() {
    return OrderID;
}

string Order::getDate() {
    return OrderDate;
}

double Order::getPrice() {
    return Price;
}

string Order::getItemName() {
    return ItemName;
}

string Order::getType() {
    return Type;
}

int Order::getQuant() {
    return Quantity;
}
