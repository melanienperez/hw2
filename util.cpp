#include <iostream>
#include <sstream>
#include <cctype>//includes isalnum (check if letter or digit), ispunct (checks if punctuation), and isspace (checks if whitespace)
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    int n = rawWords.size();
    std::set<std::string> keywords;//set with all keyboards from rawWords string
    string word = "";
    for(int i = 0; i < n; i++){
        if(!(isspace(rawWords[i]) || ispunct(rawWords[i]))){
            word = word + rawWords[i];
        } else {
            if(word.size() >= 2){
                keywords.insert(convToLower(word));//adding word to set if it is 2 or more characters long
                //case-sesitvive so have to convert to lower case before adding to set
            }
            word = "";//resetting word to empty string
        }
        if(word.size() >= 2){
            keywords.insert(convToLower(word));//adding word to set if it is 2 or more characters long
            //case-sesitvive so have to convert to lower case before adding to set
        }
    } 
    return keywords;//set with all keyboards from rawWords string

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
