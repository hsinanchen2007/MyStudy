### 解题思路
<!-- 在c++中之所以cin，cout效率低，是因为先把要输出的东西存入缓冲区，再输出，导致效率降低，
而这段语句可以来打消iostream的输入和输出缓存，可节省时间，使效率与scanf与printf相差无几。 -->
std::ios::sync_with_stdio(false);
<!-- 来解除cin与cout的绑定 -->
std::cin.tie(0);

### 代码

```cpp
class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
    }
    
    int max_value() {
        if(d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!d.empty() && d.back() < value){
                d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int res = q.front();
        if(res == d.front()){
            d.pop_front();
        }  
        q.pop();
        return res;
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