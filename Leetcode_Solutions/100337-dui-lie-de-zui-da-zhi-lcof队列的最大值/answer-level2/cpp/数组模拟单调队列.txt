- 操作次数范围是10000，最多有10000次push操作，数组大小开成10000

```
class MaxQueue {
public:
    int q[10010], hh = 0, tt = -1;
    int q_max[10010], hh_max = 0, tt_max = -1;

    MaxQueue() {
        
    }
    
    int max_value() {
        if (hh > tt) return -1;
        return q_max[hh_max];
    }
    
    void push_back(int value) {
        q[++tt] = value;
        while (hh_max <= tt_max && value > q_max[tt_max]) tt_max--;
        q_max[++tt_max] = value;
    }
    
    int pop_front() {
        if (hh > tt) return -1;
        int ret = q[hh++];
        if (q_max[hh_max] == ret) hh_max++;
        return ret;
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
