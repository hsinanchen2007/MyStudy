![image.png](https://pic.leetcode-cn.com/0f545b603f62399f6f79909ef16ff744797fc81c6dd8b412f316c3b0b922fa71-image.png)
```
#include<iostream>
#include<vector>
using namespace std;


//循环数组实现双端队列
class MyCircularDeque {
public:
	vector<int> deq;
	int size,cap,head,tail;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
    deq.assign(k,0);
		head=tail=size=0;
		cap=k;
    }
    int next(int id){
		return (id+1)%cap;
	}

	int pre(int id){
		return (id-1+cap)%cap;
	}
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
    if(isFull())
			return false;
		head=pre(head);
		deq[head]=value;
		size++;
		return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
    if(isFull())
			return false;
		deq[tail]=value;
		tail=next(tail);
		size++;    
		return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
		if(isEmpty())
			return false;
		head=next(head);
		size--;
		return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
		if(isEmpty())
			return false;
		tail=pre(tail);
		size--;       
		return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
    if(isEmpty())
			return -1;
		return deq[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
    if(isEmpty())
			return -1;
		return deq[pre(tail)];       
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```
