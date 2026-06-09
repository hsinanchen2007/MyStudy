### 解题思路
我这个是抄的，首先想想栈都需要什么，需要一个指针始终指向栈顶，还有用来存储数据的空间

### 代码

```cpp
class MinStack {
private:/**规范一点先证明变量*/
      int topp;
      int maxsize;
      int *elements;
public:
    /** initialize your data structure here. */
    MinStack() {
            topp=-1;
            maxsize=1024;
            elements=new int[maxsize];
    }
    
    void push(int x) {
        if(topp==maxsize-1) return;
        topp++;
        elements[topp] = x;

    }
    
    void pop() {
        if(topp==-1) return;
        topp=topp-1;//这块调整指针位置，相当于原来位置元素被删除了


    }
    
    int top() {
        if(topp==-1) return NULL;
        return elements[topp];

    }
    
    int getMin() {
        if(topp==-1) return NULL;
        int min=elements[0];
        for(int i=0;i<=topp;i++){
            if(min>elements[i])
            min=elements[i];
        }
        return min;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```