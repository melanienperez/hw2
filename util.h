#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    //need to add 2 iterators to iterate thru both sets
    typename std::set<T>::iterator it1 = s1.begin();
    typename std::set<T>::iterator it2 = s2.begin();
    std::set<T> intersectionSet;//set to hold intersection of s1 and s2
    while(it1 != s1.end() && it2 != s2.end()){//while loop to iterate thru both sets until one of the iterators reaches the end of its set
        if(*it1 == *it2){
            intersectionSet.insert(*it1);//adding the element to intersectionSet if it is in both s1 and s2
            it1++;
            it2++;
        }else if(*it1 < *it2){
            it1++;//incrementing it1 if the element in s1 is less than the element in s2
        }else{
            it2++;//incrementing it2 if the element in s2 is less than the element in s1
        }
    }
    return intersectionSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)//adding all elemets from s1 and s2 w/o duplicated
{
    typename std::set<T>::iterator it1 = s1.begin();
    typename std::set<T>::iterator it2 = s2.begin();
    std::set<T> unionSet;//set to hold union of s1 and s2
    while(it1 != s1.end() && it2 != s2.end()){//while loop to iterate thru both sets until one of the iterators reaches the end of its set
        if(*it1 == *it2){
            unionSet.insert(*it1);//adding the element to unionSet if it is in both s1 and s2
            it1++;
            it2++;
        }else if(*it1 < *it2){
            unionSet.insert(*it1);
            it1++;//incrementing it1 if the element in s1 is less than the element in s2
        }else{
            unionSet.insert(*it2);
            it2++;//incrementing it2 if the element in s2 is less than the element in s1
        }
    }
    while(it1 != s1.end()){
        unionSet.insert(*it1);//adding the remaining elements from s1 to unionSet
        it1++;
    }
    while(it2 != s2.end()){
        unionSet.insert(*it2);//adding the remaining elements from s2 to unionSet
        it2++;
    }
    return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
