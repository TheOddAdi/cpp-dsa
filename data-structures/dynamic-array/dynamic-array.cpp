#include <stdexcept>

class DynamicArray {
private:
    int* data;
    int count;
    int capacity;

public:
    DynamicArray() {
        data = new int[4];
        count = 0;
        capacity = 4;
    }

    DynamicArray(const DynamicArray& other) {
        count = other.count;
        capacity = other.capacity;
        data = new int[capacity];
        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }


    void push_back(int value) {
        if (count == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < count; i++) {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
        }
        data[count] = value;
        count++;
    }

    void pop_back() {
        if (count != 0) {
            count--;
        }
    }


    int get(int index) const {
        if (index >= 0 && index < count) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    int size() const {
        return count;
    }

    void insert(int index, int value) {
        if (index >= 0 && index <= count) {
            if (count == capacity) {
                capacity *= 2;
                int* newArr = new int[capacity];
                for (int i = 0; i < count; i++) {
                    newArr[i] = data[i];
                }
                delete[] data;
                data = newArr;
            }
            for (int j = count - 1; j >= index; j--) {
                data[j + 1] = data[j];
            }
            data[index] = value;
            count++;
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    void erase(int index) {
        if (index >= 0 && index < count) {
            for (int i = index; i < count - 1; i++) {
                data[i] = data[i + 1];
            }
            count--;
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }
        int* newArr = new int[capacity];
        for (int i = 0; i < count; i++) {
            newArr[i] = other.data[i];
        }
        delete[] data;
        data = newArr;
        count = other.count;
        capacity = other.capacity;
        return *this;
    }

    bool empty() const {
        return count == 0;
    }
};