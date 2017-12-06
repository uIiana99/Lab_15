//  "Copyright (C) 2017, Koshkina Uliana"

#include <iostream>
#include <ctime>

template <typename T>
class Stack {
 public:
        Stack() : array_size_(100), count_(0) {
            array_ = new T[array_size_];
        }

        explicit Stack(size_t _size) : array_size_(_size), count_(0) {
            array_ = new T[array_size_];
        }

        size_t count() const {
            return count_;
        }

        void push(T const &item) {
            if (count_ == array_size_) {
                T* new_array_ = new T[array_size_*2];

                for (int i = 0; i < array_size_; i++) {
                    new_array_[i] = array_[i];
                }
                array_size_ = array_size_ * 2;
                delete[] array_;
                array_ = new_array_;
                array_[count_++] = item;
            } else {
                array_[count_++] = item;
            }
        }

        T pop() {
            if (count_ == 0) throw std::runtime_error("empty...");
            return array_[--count_];
        }

        ~Stack() {
            delete[] array_;
        }

 private:
        T* array_;
        size_t array_size_;
        size_t count_;
};


int main() {
    srand(time(NULL));
    try {
        Stack<char> StackChar(2);
        StackChar.push('W');
        StackChar.push('O');
        StackChar.push('C');
        StackChar.push('S');
        StackChar.push('O');
        StackChar.push('M');
        size_t _StackChar_count = StackChar.count();
        for (size_t i = 0; i < _StackChar_count; i++) {
            std::cout << StackChar.pop();
        }
        std::cout << std::endl << std::endl;
        Stack<int> StackInt;
        for (int i = 0; i < 6; i++) {
            StackInt.push(1+rand_r()%999);
        }
        size_t _StackInt_count = StackInt.count();
        for (size_t i = 0; i < _StackInt_count; i++) {
            std::cout << StackInt.pop() << std::endl;
        }
    } catch(const std::exception& e) {
        std::cout << std::endl << e.what() << std::endl;
    }
}
