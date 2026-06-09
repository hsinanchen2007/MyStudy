### 解题思路
  这题怎么想都想不到O(1)，看题解发现它是均摊的。这样就好做了。使用两个队列，一个用来存放所有放进去的值，一个是维护最大值的队列。
  存放值的队列s就正常存放，维护最大值的队列q是这样的。对于所有先于它（value）进入s队列的值，如果是小于value这个值的，都可以给覆盖掉。因为队列是先进先出的，比value小的，又都是再它前面的，value就是最大值。因为想把最大值value删除，就必须把再value放进去之前的所有值给删除，包括value。

### 代码

```cpp
class MaxQueue {
public:
    //存放值
    queue<int> s;
    //维护最大值
    deque<int> q;

    MaxQueue() {

    }
    
    int max_value() {
        //维护最大值的队列为空就返回-1，否则就返回最大值
        if(q.empty())return -1;
        return q.front();
    }
    
    void push_back(int value) {
        //维护最大值，比value小的都删除。因为先于它进入，又比它小，所以可以删除，直到出现比它大的
        while(!q.empty() && q.back() < value){
            q.pop_back();
        }
        q.push_back(value);
        s.push(value);
    }
    
    int pop_front() {
        //最大值为空的，就证明所有数字都取完了
        if(q.empty())return -1;
        int t = s.front();
        //判断最大值队列的中的最大值是否是这个数值队列的开头元素，是就删掉最大值
        if(t == q.front()){
            q.pop_front();
        }
        s.pop();
        return t;
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