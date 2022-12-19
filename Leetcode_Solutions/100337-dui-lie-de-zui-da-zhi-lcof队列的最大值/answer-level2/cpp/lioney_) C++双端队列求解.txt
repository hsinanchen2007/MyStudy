```
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(dq_max.empty()) return -1;
        return dq_max.front();
    }
    
    void push_back(int value) {
        dq_data.push_back(value);
        while(!dq_max.empty() && dq_max.back() < value) {
            dq_max.pop_back();
        }
        dq_max.push_back(value);
    }
    
    int pop_front() {
        if(dq_data.empty()) return -1;
        int val = dq_data.front();
        if(val == dq_max.front()) dq_max.pop_front();
        dq_data.pop_front();
        return val;
    }
private:
    deque<int> dq_data, dq_max;
};
```
