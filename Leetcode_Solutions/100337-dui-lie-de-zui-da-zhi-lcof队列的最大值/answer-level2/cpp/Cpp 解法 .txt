### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/d36a557c7a8001203e095ed30a0243bddeff2b12877137fe2fa0bcc8dd4587b7-image.png)

### 代码

```cpp
static int n=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;}();

class MaxQueue {
    deque<int> container;
    deque<int> sorted_container;
public:
    MaxQueue() {
        container.clear();
        sorted_container.clear();
    }
    
    int max_value() {
        if(sorted_container.empty()) return -1;
        return *sorted_container.begin();
    }
    
    void push_back(int value) {
        while( !sorted_container.empty() && value > *sorted_container.rbegin())
            sorted_container.pop_back();
        sorted_container.emplace_back(value);
        container.emplace_back(value);
    }
    
    int pop_front() {
        if( container.empty() ) return -1;
        int tmp = container[0];
        if( tmp == *sorted_container.begin() ) sorted_container.pop_front();
        container.pop_front();
        return tmp;
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