### 解题思路
本题一共使用了两个知识点：
- 双栈实现队列
- 辅助栈

我们分别进行讲解：

- **双栈实现队列**

双栈实现队列，之前已经出现过类似的题目了。
由于栈的属性是FILO，而队列的属性是FIFO，所以，我们需要设定一个中间栈来进行辅助处理。
比如说输入数据[1,3,2,4]：
```
第一次push: 输入数据1，此时size为1，主栈就为[1]，副栈为[1]；
第二次push: 输入数据3，此时size为2，副栈压入数据为[3，1]，将副栈数据转入主栈为[1,3]；
第三次push: 输入数据2，此时size为3，副栈压入数据为[2, 3，1]，将副栈数据转入主栈为[1,3,2]；
第四次push: 输入数据4，此时size为4，副栈压入数据为[4，2，3，1]，将副栈数据转入主栈为[1,3，2，4].
```
主栈的pop也就实现了队列的pop功能。
这样就可以实现整个的队列功能了。

- **辅助栈**

辅助栈是指在主栈存储数据的时候，还有一个栈来实现不一样的功能，比如说，最大值和最小值之类的。
这里使用的是辅助栈来实现最大值。
由于本题是队列的性质，所以，除了比较栈顶元素外，我们还要比较之前的所有元素，这样才能保证得到的最大值是有效的。
拿样例[1,3,2,4]说明：
```
第一次push：主栈为[1]，当前值为1，{1 = 1}所以，辅助栈也为[1]；
第二次push：主栈为[1,3]，当前值为3，{3 > 1}, 所以，辅助栈内的元素为[3,3]；
第三次push：主栈为[1,3,2]，当前值为2，{2 < 3}, 所以，辅助栈内的元素为[3,3,2]；
第四次push：主栈为[1,3,2,4]，当前值为4，{4 > 3 & 4 > 2}，所以，辅助栈内的元素为[4,4,4,4]。
```
我们的判定标准就是当前值和辅助栈内所有值比较，当比值大时，压入当前值，否则压入原来的值。
这样就实现了队列的最大值序列了。

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(help_stk.empty()) return -1;
        else  return help_stk.top();
    }
    
    void push_back(int value) {
        stack<int> temp;
        //主栈
        while(!main_stk.empty()){
            temp.push(main_stk.top());
            main_stk.pop();
        }
        temp.push(value);
        while(!temp.empty()){
            main_stk.push(temp.top());
            temp.pop();
        }

        //最大栈
        while(!help_stk.empty()){
            if(value > help_stk.top()){
                temp.push(value);
            }else temp.push(help_stk.top());
            help_stk.pop();
        }

        temp.push(value);

        while(!temp.empty()){
            help_stk.push(temp.top());
            temp.pop();
        }
    }
    
    int pop_front() {
        if(main_stk.empty()) return -1;
        else{
            int res = main_stk.top();
            main_stk.pop();
            help_stk.pop();
            return res;
        }
    }
private:
    stack<int> main_stk;
    stack<int> help_stk;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```