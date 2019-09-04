#ifndef __CLASSFACTORY_
#define __CLASSFACTORY_

#include <iostream>
#include<string>
#include<map>

//���庯��ָ��
typedef void* (*create_fun)();

class ClassFactory{
public:
    ~ClassFactory() {}; 

    //������ע��ʱ������, ������ʵ��, ������
    void* getClassByName(std::string name){
        std::map<std::string, create_fun>::iterator it = my_map.find(name);
        if (it == my_map.end()) { return NULL; }

        create_fun fun = it->second;
        if (!fun) { return NULL; }

        return fun();
    }   

    //ע����������ָ�뺯����ӳ���ϵ
    void registClass(std::string name, create_fun fun){
        my_map[name] = fun;
    }   

    //����ģʽ
    static ClassFactory& getInstance(){
        static ClassFactory fac;
        return fac;
    }   

private:
    ClassFactory() {};  //˽��
    std::map<std::string, create_fun> my_map;
}; 




class Test{
public:
    Test(){ std::cout << "call Test Constructor fun" << std::endl; }
    ~Test(){ std::cout << "call Test Destructor fun" << std::endl; }
    void print(){ std::cout << "call Test print fun" << std::endl; }
};

void* create_Test(){
    Test *t = new Test;
    return (t == NULL)? NULL:t;
}

#endif