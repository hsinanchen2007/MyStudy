### 解题思路
    //得到队列的最大值，队列q为先入先出结构
    //要求均摊复杂度为O(1)，建一个辅助双端队列help保存队列最大值.如果新的value大于help尾端的值，那么help一直进行pop_back操作，直到尾端的值大于等于value 或者为空，再将value压入help的尾部；每次取max_value时，返回help首部的值；当q进行pop操作时，如果q首部的值等于help首部的值，那么help同样需要进行pop_front操作
    //队列为空时，max_value为-1

### 代码

```cpp
class MaxQueue {

public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(q.empty()) 
           return -1;
        return help.front();
    }
    
    void push_back(int value) {
        
        while(!help.empty()&&value>help.back()){
            help.pop_back();//之前help用的队列，一直提交不正确，发现原来help要用deque，在这一步pop_back
        }
        help.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int temp=q.front();
        q.pop();
        if(help.front()==temp) 
           help.pop_front();
        return temp;
    }
private:
    queue<int> q;
    deque<int> help;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```