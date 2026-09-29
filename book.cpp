#include "book.h"
#include "util.h"
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author)
    : Product(category, name, price, qty), isbn_(isbn), author_(author)
{

}

std::set<std::string> Book::keywords() const
{
    std::set<std::string> keywordsSet = parseStringToWords(name_);//adding all keywords from name_ to keywordsSet
    keywordsSet.insert(isbn_);//adding isbn_ to keywordsSet
    std::set<std::string> authorSet = parseStringToWords(author_);//adding all keywords from author_ to authorSet
    std::set<std::string> finalKeywordsSet = setUnion(keywordsSet, authorSet);//union of keywordsSet and authorSet
    return finalKeywordsSet;
}

std::string Book::displayString() const
{
    std::string displayString = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
    return displayString;
}

void Book::dump(std::ostream& os) const{
    
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}
