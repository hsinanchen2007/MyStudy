这种方法时间复杂度不符合要求，应该把最大值单独维护，如果用一个int max的话这个数被弹出以后就不知道最大值了，所以需要官方回答中的双端队列。
```
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
    int tmp=q.front();
    for(int i=0;i<q.size();i++){
        int val=q.front();
        if(tmp<val) tmp=val;
        q.pop();
        q.push(val);
    }
    return tmp;
    }
    
    void push_back(int value) {
    q.push(value);
    }
    
    int pop_front() {
    if(q.empty()) return -1;
    int tmp=q.front();
    q.pop();
    return tmp;
    }
    private:
    queue<int> q;
};

```
