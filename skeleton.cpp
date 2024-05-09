#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Cat
{
private :
    int age;
    string color;
    string name;

public : 
    Cat(int age_, string name_, string color_) : age(age_), name(name_), color(color_){}
    int getAge(){return age;}
    string getName (){return name;}
    string getColor(){return color;}
    void setAge(int age_){age=age_;}
};

void insert_cat(map<string, vector<Cat>>& m_s, map<int, vector<Cat>>& m_i, int age, string name, string color){
    Cat cat(age, name, color);
    m_s[color].push_back(cat);
    m_i[age].push_back(cat);
    return;
}

void increase_age(map<int, vector<Cat>>& m){
    for (auto item: m)
    {
        for (auto elem: item.second)
            elem.setAge(elem.getAge()+1);
    }
}

void print_info(map<string, vector<Cat>>& m){
    cout << "By color: " << endl;
    for (auto item:m){
        cout << item.first << ":\t";
        for (auto elem: item.second)    
            cout << "(" << elem.getName() << "," << elem.getAge() << ", " << elem.getColor() << ") ";
        cout << endl;
    }
}

void print_info(map<int, vector<Cat>>& m){
    cout << "By age: " << endl;
    for (auto item:m){
        cout << item.first << ":\t";
        for (auto elem: item.second)    
            cout << "(" << elem.getName() << "," << elem.getAge() << ", " << elem.getColor() << ") ";
        cout << endl;
    }
}

int main(){
    map<string, vector<Cat>> cats_by_color;
    map<int, vector<Cat>> cats_by_age;

    insert_cat(cats_by_color, cats_by_age, 5, "Whiskers", "Red");
    insert_cat(cats_by_color, cats_by_age, 4, "Shadow", "Blue");
    insert_cat(cats_by_color, cats_by_age, 4, "Paws", "Black");
    insert_cat(cats_by_color, cats_by_age, 6, "Ginger", "Orange");
    insert_cat(cats_by_color, cats_by_age, 3, "Butters", "Cheese");
    insert_cat(cats_by_color, cats_by_age, 3, "Bubbles", "Cheese");
    insert_cat(cats_by_color, cats_by_age, 4, "Sapphire", "Blue");

    cout << "----------------------Before Change------------------------" << endl;
    print_info(cats_by_color);
    print_info(cats_by_age);
    increase_age(cats_by_age);

    cout << "----------------------After Change------------------------" << endl;
    print_info(cats_by_color);
    print_info(cats_by_age);
    return 0;

}

