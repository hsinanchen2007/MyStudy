```
class MaxQueue {
public:
    queue<int> q;
    set<int> Max;
    int v;
    MaxQueue() {
    }
    
    int max_value() {
        return Max.size()?-(*Max.begin()):-1;
    }
    
    void push_back(int value) {
        q.push(value);
        Max.insert(-value);
    }
    
    int pop_front() {
        return q.empty()?-1:(v=q.front(),Max.erase(-v),q.pop(),v);
    }
};
```
set支持插入删除和自动排序 很方便的数据结构