### 解题思路
此处撰写解题思路

### 代码

```cpp

class CustomStack {
public:
    int ret[1000+10];
    int cnt = -1;
    int size = 0;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(cnt+1<size){
            ret[++cnt] = x;
        }
    }
    
    int pop() {
        if(cnt>=0){
            return ret[cnt--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i =0;i<=cnt &&i<k;i++){
            ret[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
```