#include "classfactory.h"

int main()
{
    //ע��
    ClassFactory::getInstance().registClass("Test", create_Test);

    //��ȡ�����
    Test *t = (Test*)ClassFactory::getInstance().getClassByName("Test");
    if (!t){
        std::cout << "get instnce Test err;" << std::endl;
        return 1;
    }   
    
    t->print();
    delete t;
    return 0;
}