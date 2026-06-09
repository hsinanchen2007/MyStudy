![image.png](https://pic.leetcode-cn.com/5ca374b548bcee866e5eea35d9f3a00af464243256d9e3429eef831464984342-image.png)


```
class MaxQueue {
public:

    int q[10010];
    int num[10010];
    int len =0;   //len+1
    int head = 0;

    int hh = 0;
    int tt = -1;
    MaxQueue() {
        len =0;   //len+1
        head = 0;
        hh = 0;
        tt = -1;
    }
    
    int max_value() {
        if(head == len) return -1;
        else {
            return num[q[hh]];
        }
    }
    
    void push_back(int value) {
        num[len++] = value;

        if(len==1){
            q[++tt] = len-1;
        }else{
            //if(hh<=tt && head == q[hh]) hh++;
            while(hh<=tt && num[q[tt]]<=value) tt--;
            q[++tt] = len-1;
        }
    }
    
    int pop_front() {
        if(head == len) return -1;
        else{
            if(hh<=tt && head == q[hh]) hh++;  //连续pop之后 可能maxvalue  所以要在这里进行处理
            return num[head++];
        }
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
