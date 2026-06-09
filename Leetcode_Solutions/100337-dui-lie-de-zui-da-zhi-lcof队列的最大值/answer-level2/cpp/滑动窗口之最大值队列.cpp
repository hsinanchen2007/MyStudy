# 1. 理解
初次读题，以为是道高估的中等题，很容易的想到，定义一个变量来保存队列的最大值max。在队列进行push和pop操作时更新最大值即可。实现后马上发现，在push时很容易更新最大值，但是在pop时，容易丢失历史的最大值。显然需要额外的变量来保存历史最大值，于是想到了lastMax，但显然，可能还需要lastLastMax。有限个的历史最大值是不能解决这个问题的。需要一个合适的数据结构来保存历史最大值。
这个问题本质是一个**滑动窗口求最大值问题**：出队时左边界右移，入队时右边界右移。使用**双端单调队列**解决。
## 1.1 使用双端单调队列(deque)的内在逻辑：
1. 一旦出现比之前更大的数，则最大值更新为这个数，且之前的数不可能再成为最大数(队列的先进先出原则)，则不需保存之前的数;
    - 对应操作：小于当前数的数全部出双端单调队列，当前数入双端单调队列。
2. 出现比之前小的数，在当前最大值出队后，有可能成为最大值，需要保存。
    - 对应操作：当前数直接入双端单调队列。
## 1.2 暴力方法：
使用vector模拟队列实现，通过max_element(q.begin(), q.end())方法以O(n)复杂度返回最大值。
# 2. 思路
- 新元素入队时
    1. 与deque的队首元素比较，若大于队尾元素，则队尾的这些小元素全部出队
    2. 新元素deque队尾入队，新元素queue入队
- 元素出队时
    1. 与deque的队首元素比较，若相等，则deque队首元素出队
    2. 元素queue出队
# 3. 代码
```c++
/*
暴力方法：O(n)
*/
class MaxQueue1 {
public:
    vector<int> q;
    MaxQueue1(){}
    int max_value() {
        if(q.size() > 0){
            return *max_element(q.begin(), q.end());
        }
       return -1;
    }
    
    void push_back(int value) {
        q.push_back(value);
    }
    
    int pop_front() {
        int front = -1;
        if(q.size() > 0){
            front = q.front();
            q.erase(q.begin());
        }
        return front;
    }
};
/*
双端单调队列：O(1)
*/
class MaxQueue2 {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue2(){}

    int max_value() {
       return dq.size() == 0 ? -1 : dq.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(dq.size() > 0 && value > dq.back()){ dq.pop_back();}
        dq.push_back(value);
    }
    
    int pop_front() {
        int front = -1;
        if(q.size() == 0){
            return -1;
        }
        front = q.front();
        q.pop();
        if (front == dq.front()) {dq.pop_front();}
        return front;
    }
};
```
# 4. 总结
在撸代码之前，如果不是思路特别清楚，一定要在草稿纸上写尽量详细的伪代码或逻辑思路，然后再翻译成代码实现。
在代码调试时，要定位好时语法错误还是逻辑错误。