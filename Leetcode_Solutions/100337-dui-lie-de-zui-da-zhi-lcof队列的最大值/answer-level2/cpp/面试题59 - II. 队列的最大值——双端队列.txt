关键在于理解题意中的“均摊复杂度”，只要满足每个元素入队、出队一次，即可满足“均摊复杂度为O(1)”的要求。
在正常queue之外，额外使用deque，即可满足max_value为O(1)的要求。
```
class MaxQueue {
private:
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(d.empty()){
            return -1;
        }
        return d.front();
    }
    
    void push_back(int value) {
        while(!d.empty()&&value>d.back()){
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        if(!d.empty() && q.front()==d.front()){
            d.pop_front();
        }
        int res = q.front();
        q.pop();
        return res;
    }
};
```
