### 解题思路
这个题和 **[最小栈](https://leetcode-cn.com/problems/min-stack/)** 是比较相似的，都要求 push，pop，getMin（getMax）的时间复杂度为O(1)；但是这个题要比最小栈复杂一些吗，不过同样的需要使用辅助队列来完成。

看一个入队的例子：
```cpp
入队顺序：2 9 5 3 8 6

每次入队辅助队列的正确储值：
1. 2
2. 9
3. 9 5
4. 9 5 3
5. 9 8
6. 9 8 6
```
这样：
+ getMax时直接返回辅助队列的首元素；
+ 出队时比较出队元素和辅助队列队首元素是否相同，相同则辅助队列弹出队首；
+ 入队时，循环比较辅助队列队尾元素和入队元素的大小；若入队元素大，则不断弹出队尾元素；最后将入队元素同时放在队尾

这里我们使用STL的deque。

### 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        return maxDeq.empty() ? -1 : maxDeq.front();
    }
    
    void push_back(int value) {
        while(!maxDeq.empty() && value > maxDeq.back()) {
            maxDeq.pop_back();
        }
        maxDeq.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }else{
            int ret = q.front();
            q.pop();
            if(ret == maxDeq.front()){
                maxDeq.pop_front();
            }
            return ret;
        }
    }
private:
    queue<int> q;
    deque<int> maxDeq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```