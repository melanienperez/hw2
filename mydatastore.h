#include "datastore.h"
#include "product.h"
#include "util.h"
#include <map>
#include <set>

class MyDataStore : public DataStore {
    public:
        MyDataStore();
        ~MyDataStore();
        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        void addToCart(std::string username, Product* p);
        void viewCart(std::string username);
        void buyCart(std::string username);

        private:
        std::vector<Product*> products_;
        std::vector<User*> users_;
        std::map<std::string, std::vector<Product*>> carts_;
        std::map<std::string, std::set<Product*>> keywords_;

};