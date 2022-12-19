只需要在push的时候把第一个元素放在队首进行啦。

额.. 好吧，我只是一个没有感情为了拿积分的工具人。

### 代码

```cpp
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int len = q.size();
        while (--len) {
            int top = q.front();
            q.pop();
            q.push(top);
        }
    }
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```