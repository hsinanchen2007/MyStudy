### 解题思路
测试用例：
[0][j]是指第j个调用函数，
[1][j]是指第j个函数的参数，
[2][j]是指完成第j个函数的返回值。

可以理解为滑动窗口求最大值
`queue`为一个正常的队列，负责`pop_front()`
`max_queue`是一个单调递减的双端队列，其头部为当前队列的最大值,负责`max_value()`
`pop_front()`和`max_value()`均只需要进行出队操作，所以时间复杂度为O(1)
`push_back()`中，`queue`仅进行一次入队操作，`max_queue`虽然从单个元素来看，可能会有多次`max_queue.pollLast()`,但从总体来看，`max_queue`每个元素仅需要入队一次和出队一次，所以时间复杂度
也为O(1)。
### 代码

```java
class MaxQueue {
    private Deque<Integer> queue;
    private Deque<Integer> max_queue;

    public MaxQueue() {
        queue = new ArrayDeque<>();
        max_queue = new ArrayDeque<>();
    }
    
    public int max_value() {
        if(max_queue.isEmpty()){
            return -1;
        }
        return max_queue.peekFirst();
    }
    
    public void push_back(int value) {
        queue.offer(value);
        while (!max_queue.isEmpty() && value > max_queue.peekLast()){
            max_queue.pollLast();
        }
        max_queue.offer(value);
    }
    
    public int pop_front() {
        if(queue.isEmpty()){
            return -1;
        }
        int val = queue.pop();
        if(max_queue.peek() == val) {
            max_queue.pop();
        }
        return val;
    }
}
```