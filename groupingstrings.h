#ifndef GROUPINGSTRINGS_H
#define GROUPINGSTRINGS_H
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Объявляем Group<String> для произвольного типа String
// синонимом vector<String>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор групп — vector<Group<String>>.
template <typename String>
using Group = vector<String>;

// Ещё один шаблонный синоним типа
// позволяет вместо громоздкого typename String::value_type
// использовать Char<String>
template <typename String>
using Char = typename String::value_type;

//Например, если даны строки law, port, top, laptop, pot,
//paloalto, wall, awl, нужно разбить их на 4 группы:

// строки, состоящие только из букв a, l и w: law, wall, awl;
// строки, состоящие только из букв o, p, r и t: port;
// строки, состоящие только из букв o, p и t: top, pot;
// строки, состоящие только из букв a, l, o, p, t: laptop, paloalto.


template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings) {
  // Напишите реализацию функции,
  // использовав не более 1 копирования каждого символа

  map<String, Group<String>> strKeyToGroup;

  for(String& str: strings){
    String chars = str;
    sort(begin(chars), end(chars));
    chars.erase(unique(begin(chars), end(chars)), end(chars));
    strKeyToGroup[chars].push_back(move(str));
  }
  vector<Group<String>> groups;
  for(auto& item : strKeyToGroup){
    groups.push_back(move(item.second));
  }
  return groups;
}

#endif // GROUPINGSTRINGS_H
