# 622. 设计循环队列
```
class MyCircularQueue {
private:
	int front;		//队头节点坐标
	int rear;		//队尾节点坐标
	int maxSize;	//队列最大范围
	int *queue;		//队列数组指针
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        queue = new int[k+1];	//动态生成队列数组
		maxSize = k+1;			//初始化队列最大范围
		front = 0;				//初始化队头节点坐标
		rear  = 0;				//初始化队尾节点坐标
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){	//队满无法入队
			return false;
		}else{
			rear = (rear+1)%maxSize;	//队尾后移
			queue[rear] = value;		//插入数据
			return true;
		}
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {	//队空无法出队
        if(isEmpty()){
			return false;
		}else{
			front = (front+1)%maxSize;	//对头后移
			return true;
		}
    }
    
    /** Get the front item from the queue. */
    int Front() {
		if(isEmpty())	//队空无法获取队头节点值
			return -1;
		else  
			return queue[front+1];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())  	//队空无法获取队尾节点值
			return -1;
		else  
			return queue[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if( front == rear )	//头尾节点位置相等为队空状态
			return true;
		else  
			return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if( (rear+1)%maxSize == front )	//尾节点下一个位置尾头结点为队满状态
			return true;
		else  
			return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
