#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <regex>
int main(int argc, char* argv[]) {
    if(argc==3) {
        int allSymbols = 0;
        std::list<std::pair<float, std::string>> myList;
        std::list<std::pair<float, std::string>>::iterator iterator_list;
        std::map<std::string, float> myMap;
        std::map<std::string, float>::iterator it;
        std::ifstream fin;
        std::ofstream out;
        fin.open(argv[1]);
        out.open(argv[2]);

        if (!fin.is_open()) {
            std::cout << "Can't open the file" << std::endl;
        }
        else {
            std::cout << "File is opened" << std::endl;
            std::string str;
            while (std::getline(fin, str)) {
                std::regex re("[^a-zA-Z0-9]"); // Separators everything except letters and numbers
                std::sregex_token_iterator p(str.begin(), str.end(), re, -1);
                std::sregex_token_iterator end;
                while (p != end) {
                    it = myMap.find(*p);
                    if (it == myMap.end()) {
                        myMap[*p] = 1;
                    } else {
                        myMap[*p]++;
                    }
                    *p++;
                    allSymbols++;

                }
            }
        }
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            myList.push_back(std::make_pair(it->second, it->first));
        }
        myList.sort();
        for (auto iterator_list = myList.rbegin(); iterator_list != myList.rend(); ++iterator_list) {
            out << iterator_list->second << ";" << iterator_list->first << ";"<< ((iterator_list->first) / allSymbols) * 100 << "%" << std::endl;
        }
        fin.close();
        out.close();
    }
    else{
        std::cout<<"Not enough arguments"<<std::endl;
        return 0;
    }

    std::cout<<"Wrods have been counted!"<<std::endl;
     return 0;
}
