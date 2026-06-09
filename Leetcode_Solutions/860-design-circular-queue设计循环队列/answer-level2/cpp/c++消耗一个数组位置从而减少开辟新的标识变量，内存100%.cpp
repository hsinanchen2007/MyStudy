### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyCircularQueue {
    int length;
    int front;
    int rear;
    int *data;
public:

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this->length=k;
        this->front=0;
        this->rear=0;
        data=new int[k+1];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        data[rear]=value;
        rear=(rear+1)%(length+1);
        return true;

    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) { return false;}
        front=(front+1)%(length+1);
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){return -1;}
        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){return -1;}
         if(rear==0){ return data[length];}
        return data[rear-1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return rear==front;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {

        return (rear+1)%(length+1)==front;
    }
};
