### 解题思路
用一个额外的双端队列存储对当前队列有影响的值, 这个双端队列是非增的, 并且双端队列队首元素为当前最大值. 具体来说, 当一个元素$a$入队时, 将双端队列队尾的小于$a$的元素全部出队. 这是因为在$a$出队之前, 这些元素不可能为最大值; 当一个元素$b$出队时, 则看它是否为最大元素, 如果是, 则将双端队列队首元素也出队, 否则$b$不影响最大值的计算, 无需队双端队列进行操作.

### 代码
```
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int result = q.front();
        if (result == d.front()) {
            d.pop_front();
        }
        q.pop();
        return result;
    }
};
```