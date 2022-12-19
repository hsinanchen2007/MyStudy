额,思路就是,用两个队列,一个当然是存值,一个当单调栈,存递减的最大值序列.
均摊都是O(1).
举个栗子:
queue1  queue2
9       9
93      93
934     94
9343    943
93435   95
```
class MaxQueue {
public:
    vector<int> q;
    vector<int> s;
    int q_head = 0;
    int q_tail = 0;
    int s_head = 0;
    int s_tail = 0;

    MaxQueue() {
        s = vector<int>(1000);
    }
    int max_value() {
        if(s_head == s_tail) return -1;
        return s[s_head];
    }
    
    void push_back(int value) {
        q.push_back(value);
        q_tail++;        
        while(s_tail>s_head && s[s_tail-1]<value){
            s_tail--;
        }
        s[s_tail++] = value;
    }
    
    int pop_front() {
        if(q_tail == q_head) return -1;
        int t = q[q_head++];
        if(s[s_head] == t){
            s_head++;
        }
        return t;
    }
};
```