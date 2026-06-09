引入一个数组，长度设置为k+1,即需要牺牲一个存储空间。约定rear==front时为空，（rear+1）%MAXSIZE==front时为满。其中MAXSIZE=k+1;```
class MyCircularQueue {
public:

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        MAXSIZE=k+1;
        Q.resize(k+1);
        front=rear=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        else{
            rear=(rear+1)%MAXSIZE;
            Q[rear]=value;
            return true;
        }
           
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        else
        {
             front=(front+1)%MAXSIZE;
            return true;
        }
           
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        else
        {
        return Q[(front+1)%MAXSIZE];
        }
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        else
          return Q[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(rear==front) return true;
        else return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((rear+1)%MAXSIZE==front) return true;
        else return false;
    }
 private:
    vector<int> Q;
    int front,rear;
    int MAXSIZE;
};
```
