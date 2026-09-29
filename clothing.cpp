#include "clothing.h"
#include "util.h"
#include <iostream>
#include <iomanip>
using namespace std;
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand)
    : Product(category, name, price, qty), size_(size), brand_(brand)
{   

}
std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> keywordsSet = parseStringToWords(name_);//adding all keywords from name_ to keywordsSet
    std::set<std::string> brandSet = parseStringToWords(brand_);//adding all keywords from brand_ to brandSet
    std::set<std::string> finalKeywordsSet = setUnion(keywordsSet, brandSet);//union of keywordsSet and brandSet
    return finalKeywordsSet;
}

std::string Clothing::displayString() const
{
    std::stringstream ss;
    
    ss<< name_ << "\n"
    << "Size: " << size_ << " Brand: " << brand_ << "\n"
    <<fixed << setprecision(2) << price_ << " " << qty_ << " left.";
    return ss.str();
}

void Clothing::dump(std::ostream& os) const{
    
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}
