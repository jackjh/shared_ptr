#include "shared_ptr.h"

int main() {
    {
        shared_ptr<int> ptr(new int(88));
        {
            shared_ptr<int> ptr_1(ptr);
            shared_ptr<int> ptr_2 = ptr_1;
        }
        std::cout << "{} inside finished" << std::endl;
    }
    std::cout << "{} outside finished" << std::endl;

    return 0;
}