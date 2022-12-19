### 解题思路
eg输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]

首先这个题目是需要自定义一个队列，实现入队、出队以及求最大值的操作！
第一个列表（表示用定义好的队列来依次操作）：
    ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
    表示————用定义好的队列依次进行，MaxQueue、push_back、...、max_value操作，
第二个列表（表示第一个列表对应的操作数）：
    [[],[1],[2],[],[],[]]
    表示————第一个列表对应的操作数，例如第一个"push_back"将1入队，第二个"push_back"将2入队，第一个"max_value"求当前队列中最大值（显然为2）。。。
理解了上面的意思，那么输出自然好理解：
    null,null,null,2,1,2]
### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(que.empty()) return -1;
        return *max_element(que.begin(), que.end());
    }
    
    void push_back(int value) {
        que.emplace_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        int front = que[0];
        que.erase(que.begin());
        return front;
    }
private:
    vector<int> que;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```