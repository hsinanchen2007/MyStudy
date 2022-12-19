#include <math.h>
#include <assert.h>
using namespace std;

template<typename E>
class BinaryHeap {
private:
    E *container = NULL;
    unsigned int capacity = 0;
    unsigned int size = 0;
    unsigned getLeftChildIndex(unsigned index) {
        return index * 2 + 1;
    }

    unsigned getRightChildIndex(unsigned index) {
        return this->getLeftChildIndex(index) + 1;
    }

    unsigned getParentIndex(unsigned index) {
        int parentIndex = ceil((double)index / 2) - 1;
        if (parentIndex < 0) {
            return 0;
        }
        return parentIndex;
    }

    unsigned getLastParentIndex() {
        return this->getParentIndex(this->getSize() - 1);
    }

    void shiftUp(unsigned index) {

        while ((index > 0) && this->container[index] < this->container[this->getParentIndex(index)]) {
            swap(this->container[index], this->container[this->getParentIndex(index)]);
            index = this->getParentIndex(index);
        }

    }

public:
    
    void shiftDown(unsigned index = 0) {
        E e = this->container[index];
        while(this->getSize() > getLeftChildIndex(index)) {
            unsigned maxOrMinChildIndex = getLeftChildIndex(index);
            if (this->getSize() > getRightChildIndex(index)) {
                if (this->container[getRightChildIndex(index)] < this->container[getLeftChildIndex(index)]) {
                    maxOrMinChildIndex = getRightChildIndex(index);
                }
            }
            if (e <= this->container[maxOrMinChildIndex]) {
                break;
            }
            this->container[index] = this->container[maxOrMinChildIndex];
            index = maxOrMinChildIndex;
        }
        this->container[index] = e;
    }
    
    BinaryHeap(unsigned capacity) {
        
        this->container = new E[capacity];
        this->capacity = capacity;
    }

    void insert(E element) {
        
        this->container[this->size] = element;
        this->shiftUp(this->size);
        this->size ++;
    }

    E extract() {
        assert(!this->isEmpty());
        E root = this->getRoot();
        E tail = this->container[this->getSize() - 1];
        this->setRoot(tail);
        this->shiftDown();
        this->size --;
        return root;
    }

    E replace(E element) {
        E root = this->getRoot();
        this->setRoot(element);
        shiftDown();
        return root;
    }

    E getRoot() {
        return this->container[0];
    }

    void setRoot(E element) {
        this->container[0] = element;
    }

    bool isEmpty() {
        return this->getSize() == 0;
    }

    unsigned getSize() {
        return this->size;
    }

    bool isFull() {
        return this->size >= this->capacity;
    }

    
    ~BinaryHeap() {
        delete(this->container);
    }

};

class KthLargest {
public:
    BinaryHeap<int> *minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->minHeap = new BinaryHeap<int>(k + 1);
        this->k = k;
        for (int i = 0; i < nums.size();i ++) {
            this->add(nums[i]);      
        }
    }
    
    int add(int val) {
       
        this->minHeap->insert(val);
        
        if (this->minHeap->isFull()) {
            this->minHeap->extract();
        }
        
        return this->minHeap->getRoot();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */