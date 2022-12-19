### 解题思路
简单的用数组模拟栈，不算难~

### 代码

```cpp
class CustomStack {
    #define ll long long
    #define rg register ll
    int a[1005],top,size;
public:
    CustomStack(int maxSize) {
        size=maxSize;
        top=0;
    }
    
    void push(int x) {
        if(top<size)a[top++]=x;

    }
    
    int pop() {
        if(!top)return -1;
        return a[--top];
    }
    
    void increment(int k, int val) {
        for(rg i=0,n=min(k,size);i<n;i++)a[i]+=val;
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