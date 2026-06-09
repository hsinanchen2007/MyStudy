```C++ []
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(max_que.empty())
            return -1;
        return max_que.front();

    }
    
    void push_back(int value) {
        que.push(value);
       
        while(!max_que.empty() && value > max_que.back())
            max_que.pop_back();
        max_que.push_back(value);
      

    }
    
    int pop_front() {
        if(que.empty())
            return -1;
        int tmp = que.front();
        que.pop();
        if(tmp == max_que.front())
            max_que.pop_front();
        return tmp;

    }
private:
    queue<int> que;
    deque<int> max_que;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```


