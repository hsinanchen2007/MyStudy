**方法一：用两个数组维护**
```
class MaxQueue {
    /**
    * 思路：
    * 维护两个数组，一个正常模拟push和pop，另一个维护剩余队列中所有可能的最大值。
    */
    int[] Queue;
    int[] MAXQueue;
    int QueueHead, QueueTail, MAXQueueHead, MAXQueueTail;

    public MaxQueue() {
        Queue = new int[10000];
        MAXQueue = new int[10000];
    }
    
    public int max_value() {
        if(MAXQueueHead == MAXQueueTail){
            // 头尾相等的时候，表示此时队列为空，没有最大值
            return -1;
        }
        return MAXQueue[MAXQueueHead];
    }
    
    public void push_back(int value) {
        Queue[QueueTail++] = value;
        while(MAXQueueHead != MAXQueueTail && MAXQueue[MAXQueueTail-1] < value){
            // MAXQueueTail-1 因为MAXQueueTail处的值是0，还没有被初始化
            // 比value小的值，一定会在value出队列前，先出队列，max_value方法只是获取最大值
            // 队列中在做pop_front到value之前，队列中最大值都大于等于value
            MAXQueueTail--;
        }
        MAXQueue[MAXQueueTail++] = value;

    }
    
    public int pop_front() {
        if(QueueHead == QueueTail){
            // 队列为空
            return -1;
        }
        int res = Queue[QueueHead];
        if(res == MAXQueue[MAXQueueHead]){
            MAXQueueHead++;
        }
        QueueHead++;
        return res;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```
