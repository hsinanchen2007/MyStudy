### 解题思路
此处撰写解题思路

### 代码

```Java []
class MaxQueue {

    int[] queue = new int[10001];
    int QueueHead = 0;
    int QueueTail = 0;
    
    int[] maxQueue = new int[10001];
    int MaxQueueHead = 0;
    int MaxQueueTail = 0;
    
    public MaxQueue() {

    }
    
    public int max_value() {
        if (MaxQueueHead == MaxQueueTail) return -1;
        else return maxQueue[MaxQueueHead]; 
    }
    
    public void push_back(int value) {
        queue[QueueTail++] = value;
        while(MaxQueueHead != MaxQueueTail && maxQueue[MaxQueueTail-1] < value){
            MaxQueueTail--;
        }
        maxQueue[MaxQueueTail++] = value;
    }
    
    public int pop_front() {
        if (QueueHead == QueueTail) return -1;
        if(queue[QueueHead] == maxQueue[MaxQueueHead])
            MaxQueueHead++;
        return queue[QueueHead++];

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

```rust []
struct MaxQueue {
    queue:Vec<i32>,
    max_queue:Vec<i32>,
    queueHead:usize,
    queueTail:usize,
    maxqueueHead:usize,
    maxqueueTail:usize,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MaxQueue {

    fn new() -> Self {
        Self{
            queue : vec![0;10001],
            max_queue : vec![0;10001],
            queueHead:0,
            queueTail:0,
            maxqueueHead:0,
            maxqueueTail:0,
        }
    }
    
    fn max_value(&self) -> i32 {
        if self.maxqueueHead == self.maxqueueTail{
            return -1;
        }
        else{
            return self.max_queue[self.maxqueueHead]
        }
    }
    
    fn push_back(&mut self, value: i32) {
        self.queue[self.queueTail] = value;
        self.queueTail += 1;
        while ((self.maxqueueHead != self.maxqueueTail) &&                 (self.max_queue[self.maxqueueTail-1] < value)){
            self.maxqueueTail -= 1;
        }
        self.max_queue[self.maxqueueTail] = value;
        self.maxqueueTail+=1;
    }
    
    fn pop_front(&mut self) -> i32 {
        if self.queueHead == self.queueTail {
            return -1
        }
        let tmp = self.queue[self.queueHead];
        if tmp == self.max_queue[self.maxqueueHead]{
            self.maxqueueHead += 1;
        }  
        self.queueHead += 1;
        return tmp;
        
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * let obj = MaxQueue::new();
 * let ret_1: i32 = obj.max_value();
 * obj.push_back(value);
 * let ret_3: i32 = obj.pop_front();
 */
```