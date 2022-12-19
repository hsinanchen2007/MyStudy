### 解题思路
很简单的思路 用STL的queue相关函数
push()加入队列
pop()出队列
front()获取队首元素
***易错点1.***
找最大元素的时候：是要依此取出队首元素和存好的max进行比较，最后取到队列为空。所以不能从定义的队列q中直接取，这样会影响后续操作。
所以**定义了一个p**，和q一样，对p操作。
***易错点2.***
pop_front函数
是取出队首元素，并将队首元素**弹出**。不要忘记弹出！


### 代码

```cpp
class MaxQueue {
public:
    queue<int> q;
    MaxQueue() {
        
    }
    
    int max_value() {
        queue<int> p=q;
        if(p.size()==0)
            return -1;
        int max = p.front();
        p.pop();
        while(p.size()){
            if(p.front()>max)
                max=p.front();
            p.pop();
        }
        return max;
    }
    
    void push_back(int value) {
        q.push(value);
    }
    
    int pop_front() {
        if(q.size()==0)
            return -1;
        int m=q.front();
        q.pop();
        return m;
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