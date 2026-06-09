
#### 题目的限制条件：
1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

题目给的限制条件，限制了操作的总数，就可以使用最原始的数据结构，数组来进行解题
数组的长度为限定的操作总数

该题是要模拟队列，而且要求的时间复杂度都是O(1)，用空间换时间（数组赋予可能的最大的长度）
使用两个数组，一个数组Queue模拟正常队列的入队和出队；一个数组MAXQueue用于实现max_value()方法，MAXQueue数组中的元素是递减的
使用头尾指针来模拟入队和出队的操作

为什么使用MAXQueue来记录队列中的最大值？
    题目要求的时间复杂度都是O(1)，只用单个的int对象来记录最值的话，一旦最值被pop，那么对队列中之前添加的元素就没有了任何的记录，不知道谁是此时最大的，需要重新的遍历队列，这样做时间复杂度不符合要求，所以要用数组记录添加到队列中的元素，并由大到小的排列。优化该数组的分析在下面写了 

### 分析
1. max_value()
    如果MAXQueueHead == MAXQueueTail 表示队列中没有元素，返回-1
    在MAXQueue的头指针的位置保存的就是此时队列中的最大值，直接的取值就可以，时间复杂度是O(1)
2. push_back(): 
    Queue数组正常的进行添加数据，Queue[QueueTail++] = value;
在进行入队的时候，在MAXQueue中需要进行判断，时间复杂度均摊下来也是O(1)： 
    比value小的值，一定会在value出栈前，先出栈，队列中的最大值最少都是value，就没有保存比value小的值的必要了，MAXQueueTail指向的索引，在数组MAXQueue中还没被赋值，判断的时候需要使用MAXQueueTail-1
`MAXQueue[MAXQueueTail-1] < value`
3. pop_front()
    Queue中Head的值 与 MAXQueue中Head的值相等，则两个数组中的head都要 ++ ，因为最大值已经变了 
    不然，就是常规的Queue中的head++，时间复杂度是O(1)


### 代码

```java
class MaxQueue {

    int[] Queue;
    int QueueHead = 0;
    int QueueTail = 0;
    int[] MAXQueue;
    int MAXQueueHead = 0;
    int MAXQueueTail = 0;

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
            // 比value小的值，一定会在value出栈前，先出栈，
            // 队列中的最大值最少都是value，就没有保存比value小的值的必要了
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