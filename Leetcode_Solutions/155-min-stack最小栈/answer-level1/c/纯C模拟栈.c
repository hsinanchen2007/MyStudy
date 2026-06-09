![捕获.JPG](https://pic.leetcode-cn.com/94a947e89bdf6359e3e3283acdeab999dfb066d613fc97e547b740ff86d44555-%E6%8D%95%E8%8E%B7.JPG)

### 解题思路
超简单，就是模拟一个栈，然后另外一个数组保存已经入栈的元素和当前入栈元素的最小值。
这题没有非法操作，所以不用写的很麻烦。
### 代码

```cpp

class MinStack {
public:
    /** initialize your data structure here. */
    const static int maxn=1e4+10;
    int a[maxn],p;
    int st[maxn];
    MinStack() {
        p=0;
    }
    
    void push(int x) {
        st[p]=x;
        a[p]=min((p-1>=0?a[p-1]:(1<<31)-1),x);
        p++;
    }
    
    void pop() {
        p--;
    }
    
    int top() {
        return st[p-1];
    }
    
    int getMin() {
        return a[p-1];
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