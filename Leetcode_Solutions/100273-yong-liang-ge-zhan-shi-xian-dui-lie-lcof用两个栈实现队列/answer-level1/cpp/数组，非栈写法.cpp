用数组搞的，，也能过，，不知道有没有什么问题

我错了，才发现题目是要求用栈
```
class CQueue {
public:
    vector<int> res; 
    int now = 0;
    int out = 0;
    CQueue() {
       res.resize(11000);
    }
    
    void appendTail(int value) {
        res[now] = value;
        now++;
    }
    
    int deleteHead() {
        if(res[out]==0) return -1;
        else {
            int a = res[out];
            out++;
            return a;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

大吉
