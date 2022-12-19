解题思路：
    首要明确目标，push、pop、max_value都需要O(1)复杂度。max_value不用说，队空返回-1，否则返回最大值。那么我们就需要一个变量保存maxvalue，但仅用一个int变量做不到在pop时更新maxvalue，因为我们没法在O(1)的情况下找到pop出最大值之后队列的最大值。因此我们就需要维护有序的序列，在第一个最大值pop出后会有第二个最大值来进行替换。也就是说我们需要一个单调递减的序列，pop、push过程已经清晰了，当pop最大值时同时pop出序列的第一个元素。在push时，我们需要维护递减的序列，如果序列的最后一个元素小于当前值就去除最后一个值并重复此过程，最后把该元素插入到该递减序列。虽然push中存在一个循环，这里引用官方题解的说明：而插入操作虽然看起来有循环，做一个插入操作时最多可能会有 n 次出队操作。但要注意，由于每个数字只会出队一次，因此对于所有的 n 个数字的插入过程，对应的所有出队操作也不会大于 n 次。因此将出队的时间均摊到每个插入操作上，时间复杂度为 O(1)。
```
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(que.size() == 0)
            return -1;
        return dque.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while(!dque.empty() && dque.back() < value)
            dque.pop_back();
        dque.push_back(value);
    }
    
    int pop_front() {
        if(que.size() == 0)
            return -1;
        int temp = que.front();
        que.pop();
        if(temp == dque.front())
            dque.pop_front();
        return temp;
    }
private:
    queue<int> que;
    deque<int> dque;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```
