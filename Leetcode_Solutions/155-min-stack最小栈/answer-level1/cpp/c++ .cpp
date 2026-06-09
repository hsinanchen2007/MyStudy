### 解题思路
非常简单的题 利用数组的快速遍历查找

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        i=0;
    }
    
    void push(int x) {
        i++;
        aa[i]=x;
    }
    
    void pop() {
        i--;
    }
    
    int top() {
        return aa[i];
    }
    
    int getMin() {
        int j=1;
        int min=aa[j];
        for(j=2;j<=i;j++){
            if(aa[j]<min)min=aa[j];
        }
        return min;
    }
    private:
    int aa[10000];
    int i;
};
























/*class MinStack {
public:
    /** initialize your data structure here. 
    MinStack() {
        i=0;
    }
    
    void push(int x) {
        i++;
        aa[i]=x;
    }
    
    void pop() {
        --i;
    }
    
    int top() {
        return aa[i];
    }
    
    int getMin() {
        int j=1;
        long long min=aa[j];
        for(j=2;j<=i;j++){
            if(aa[j]<min)
            min=aa[j];
        }
        return min;
    }
    private:
        long long aa[10000];
        int i;
};*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```