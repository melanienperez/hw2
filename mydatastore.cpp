#include "mydatastore.h"
#include <iostream>
#include <iomanip>


MyDataStore::MyDataStore() {
    // Constructor implementation
}
MyDataStore::~MyDataStore() {
    // Destructor implementation
  std::vector<Product*>::iterator itP = products_.begin();
    for(; itP != products_.end(); itP++){
        delete *itP;
    }
    std::vector<User*>::iterator itU = users_.begin();
    for(; itU != users_.end(); itU++){
        delete *itU;
    }
}

void MyDataStore::addProduct(Product* p) {
    products_.push_back(p);
    std::set<std::string> productKeywords = p->keywords();
    std::set<std::string>::iterator it = productKeywords.begin();
    for(; it != productKeywords.end(); it++) {
        keywords_[convToLower(*it)].insert(p);
    }
}
void MyDataStore::addUser(User* u) {
    users_.push_back(u);
    carts_[u->getName()] = std::vector<Product*>();
}

void MyDataStore::addToCart(std::string username, Product* p) {
    if (carts_.find(username) == carts_.end()) {
        std::cout << "Invalid request" << std::endl;
        return;
    }

    if(p->getQty() > 0) {
        carts_[username].push_back(p);
    }

}

void MyDataStore::viewCart(std::string username) {
    std::vector<Product*>& cart = carts_[username];

    int resultNo = 1;
    std::vector<Product*>::iterator it = cart.begin();
    for(; it != cart.end(); it++){
        std::cout << "Hit " << std::setw(3) << resultNo << std::endl;
        std::cout << (*it)->displayString() << std::endl;
        std::cout << std::endl;
        resultNo++;
    }
}

void MyDataStore::buyCart(std::string username) {
    std::vector<Product*>& cart = carts_[username];
     User* user = nullptr;

     std::vector<User*>::iterator itUser = users_.begin();
     for (; itUser != users_.end(); itUser++) {
         if ((*itUser)->getName() == username) {
             user = *itUser;
             break;
         }
     }

     std::vector<Product*>::iterator itP = cart.begin();
        for(; itP != cart.end(); itP++){

            Product* p = *itP;
            if(p->getQty() > 0 && user->getBalance() >= p->getPrice()){
                user->deductAmount(p->getPrice());
                p->subtractQty(1);
            }
     }
     cart.clear();
 
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    std::set<Product*> resultSet;

    if (terms.empty()) {
        return std::vector<Product*>();
    }

    int numTerms = terms.size();
    for (int i = 0; i < numTerms; i++) {
        if (keywords_.find(terms[i]) != keywords_.end()) {
            if (i == 0) { 
                resultSet = keywords_[terms[i]];
            } else if (type == 0){ 
                resultSet = setIntersection(resultSet, keywords_[terms[i]]);
            } else {
                resultSet = setUnion(resultSet, keywords_[terms[i]]);
            }
        } else if (type == 0) { 
            resultSet.clear();
        }
    }

    return std::vector<Product*>(resultSet.begin(), resultSet.end());
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>" << std::endl;
    std::vector<Product*>::iterator itP = products_.begin();
    for(; itP != products_.end(); itP++){
        (*itP)->dump(ofile);
    }
    ofile << "</products>" << std::endl;

    ofile << "<users>" << std::endl;
    std::vector<User*>::iterator itU = users_.begin();
    for(; itU != users_.end(); itU++){
        (*itU)->dump(ofile);
    }
    ofile << "</users>" << std::endl;
}