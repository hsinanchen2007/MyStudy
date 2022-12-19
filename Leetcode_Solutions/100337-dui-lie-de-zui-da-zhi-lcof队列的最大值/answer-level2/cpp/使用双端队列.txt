### 解题思路
使用普通队列来进行入队和出队操作，问题中的难点就只有记录最大值，并且在出队时操作时间为O(1)。
使用双端队列来解决最大值的问题，当每个值进来入队时，如果该值比队尾的值大，则让队尾的值出队，直到队尾的值比该值大，然后将该值入队。当取最大值时，取队首元素，当pop_front()时，普通队列和双端队列中的对应值一定是一起出队的，那就同步更新了最大值。其实可以理解为双端队列中的各个元素代表了队列中每个元素与后面入队元素中的最大值。

### 代码

```cpp
class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {

    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!d.empty() && d.back() < value)
            d.pop_back();
        d.push_back(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int v = q.front();
        if (q.front() == d.front())
            d.pop_front();
        q.pop();
        return v;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```