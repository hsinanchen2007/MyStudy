### 解题思路
解题思路是来自用户陈乐乐的思考。
设置一个数据栈data存数据；
在设置一个辅助栈用来存最小值，只要遇到和当前一样或者小的数值，就入栈；
还有一些缩减执行时间的注释写在代码里。

还有一种用一个栈解决的方法，就是将数据栈和辅助栈重合成一个栈。思路一致
### 代码

```cpp
class MinStack {
private:
//将数据栈和辅助栈设置为私有变量后，执行用时从32ms缩减到24ms
stack<int> data;
stack<int> min;
public:
    /** initialize your data structure here. */
   
    void push(int x) {
        data.push(x);
        //使用if语句，耗时52ms,使用while语句，耗时32ms
        while(min.empty()||x<=min.top())
            {
              min.push(x);
                break;  
            }
    }
    
    void pop() {
        if(data.top()==min.top())
            min.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();

    }
};

