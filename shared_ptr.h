#ifndef SHARED_PTR_H_
#define SHARED_PTR_H_

#include <iostream>

template<class T>
class shared_ptr;

template<class T>
class resource_ptr {
private: 
    T* res_ptr;
    int use_cnt;

    resource_ptr(T* ptr) : res_ptr(ptr), use_cnt(1) {
        std::cout << "resource_ptr constructor" << std::endl;
    }

    ~resource_ptr() {
        delete res_ptr;
        std::cout << "resource_ptr deconstructor" << std::endl;
    }

    //template<class T>
    friend class shared_ptr<T>;
};

template<class T> 
class shared_ptr {
private: 
    resource_ptr<T>* r_ptr;

public: 
    shared_ptr(T* ptr) : r_ptr(new resource_ptr<T>(ptr)) {
        std::cout << "shared_ptr constructor" << std::endl;
    }

    shared_ptr(const shared_ptr& origin) : r_ptr(origin.r_ptr) {
        r_ptr->use_cnt += 1;
        std::cout << "shared_ptr copy constructor" << "use_cnt = " << r_ptr->use_cnt << std::endl;
    }

    ~shared_ptr() {
        std::cout << "shared_ptr deconstructor" << std::endl;

        if((--r_ptr->use_cnt) == 0) {
            delete r_ptr;
        }
    }
};


#endif