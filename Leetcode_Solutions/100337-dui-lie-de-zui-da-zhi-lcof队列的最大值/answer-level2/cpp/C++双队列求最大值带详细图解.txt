### 解题思路
#### 题目
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。
#### deque & queue
deque是双向队列，相对于queue可以从头部和尾部进行操作
#### 图解思路
![截屏2020-03-07上午11.08.56.png](https://pic.leetcode-cn.com/e3117482b6f89522e2c72191b856ba97e502d9285aff967196f52fa659c394b8-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8811.08.56.png)
![Image001.jpg](https://pic.leetcode-cn.com/047964312c1021345495550582593afe4155ca6c01c942c4a2189907930988aa-Image001.jpg)


### 代码

```cpp
class MaxQueue {
public:
    queue<int> Q;
    deque<int> D;

    MaxQueue() {
    }
    
    int max_value() {
        if(Q.empty()) return -1;
        return D.front();
    }
    
    void push_back(int value) {
        while(!D.empty() && D.back() < value) D.pop_back();
        D.push_back(value);
        Q.push(value);
    }
    
    int pop_front() {
        if(Q.empty()) return -1;
        int ans = Q.front();
        if(ans == D.front())
        {
            D.pop_front();
        }
        Q.pop();
        return ans;

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