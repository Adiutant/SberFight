#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
//Вам даётся массив имён трёх братьев и массив утверждений, которые являются правдивыми. Список возможных утверждений:
//
//“is youngest” – самый младший
//“is not youngest” – не самый младший
//“is not oldest” – не самый старший
//“is oldest” – самый старший
//Вам предстоит расставить всех братьев по возрастанию возраста
// Ввод:
//
//names – массив имён трёх братьев, length(names)=3
//statements – массив(string[]), statements[i] = [“a-b”], где a – имя брата, b – утверждение, их разделяет тире без пробелов. Для одного брата может быть несколько утверждений
// Вывод:
//
//String[] – список братьев от самого младшего до самого старшего, решение всегда есть и всегда одно
//Example:
struct person {
    string name;
    bool isOldest=true;
    bool isMiddle=true;
    bool isYoungest=true;
};
vector<std::string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
        // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
    }
    return elems;
}
vector<string> getResult(vector<string> names, vector<string> statements)
{
    map<string,person> persons;
    //persons.reserve(names.size());
    for (auto& name : names)
    {
        persons[name] ={name};
    }
    for (auto&statement : statements)
    {
        string name;
        string state;
        name = split(statement,'-')[0];
        state = split(statement,'-')[1];
        if (state == "is youngest")
        {
            persons[name].isOldest = false;
            persons[name].isMiddle = false;
            for (auto& lname : names)
            {
                if (lname!=name)
                {
                    persons[lname].isYoungest = false;
                }
            }
        }
        if (state == "is not youngest")
        {
            persons[name].isYoungest = false;
        }
        if (state == "is not oldest")
        {
            persons[name].isOldest = false;
        }
        if (state == "is oldest")
        {
            persons[name].isYoungest = false;
            persons[name].isMiddle = false;
            for (auto& lname : names)
            {
                if (lname!=name)
                {
                    persons[lname].isOldest = false;
                }
            }
        }
    }
    vector<string> result{"","",""};
    for (auto lname : names)
    {
        if (persons[lname].isOldest)
        {
            result[2] = lname;
        }
        if (persons[lname].isMiddle&&!persons[lname].isOldest&&!persons[lname].isYoungest)
        {
            result[1] = lname;
        }
        if (persons[lname].isYoungest)
        {
            result[0] = lname;
        }
    }
    return result;

}

int main()
{
    vector<string>names={"Kevin", "Jack", "Mark"};
    vector<string>statements={"Kevin-is not youngest", "Jack-is oldest", "Mark-is not oldest"};
    vector<string> result = getResult(names,statements);
    for (auto item:result)
    {
        cout<<item<<endl;
    }
    // Entrypoint to debug your function
}
