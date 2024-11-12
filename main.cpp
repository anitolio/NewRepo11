#include <iostream>
#include "ForwardList.h"

int main() {
    ForwardList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();

    ForwardList anotherList(list);
    anotherList.print();

    return 0;
}
