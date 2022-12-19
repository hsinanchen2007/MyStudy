### 解题思路
声明两个栈s1,s2. s1为主，s2为辅助栈.关键是出栈，这里不妨这样考虑：由于我们数据进栈是push在s1中，所以要实现队列思想，首先进栈的元素是首先出来，但是单个s1栈无法实现，所以要辅助栈s2.这里画一下就可以得到这样结论： s1最后出栈的元素一定在s2栈顶，所以每次删除元素时只需要判断s2是否为空，如果不为空，直接删除S2栈顶元素就可以了。（我们设置当s2中有数据时，s1数据不能push到s2）

### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    //以s1为主，s2为辅.
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int a;
        if(s1.empty() && s2.empty())
            return -1;
        if(!s2.empty()){
            a = s2.top();
            s2.pop();
            return a;
        }else{
            while(!s1.empty()){
                a = s1.top();
                s2.push(a);
                s1.pop();
            }
            a = s2.top();
            s2.pop();
            return a;
        }

    }

    private:
     stack<int> s1;
     stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```