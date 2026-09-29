#include "movie.h"
#include "util.h"
#include <iostream>
#include <iomanip>
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating)
    : Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> keywordsSet = parseStringToWords(name_);//adding all keywords from name_ to keywordsSet
       keywordsSet.insert(genre_);//adding genre_ to keywordsSet
    return keywordsSet;
}

std::string Movie::displayString() const
{
    std::string displayString = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.";
    return displayString;
}

void Movie::dump(std::ostream& os) const{
    
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}
