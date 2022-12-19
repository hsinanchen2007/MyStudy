`pop`和`front`都需要对队列反转操作，完整的过程是这样的 ↓↓↓
![演示文稿3.gif](https://pic.leetcode-cn.com/c3f78dcb47e8acb7311f98672bc961a9fc96cc4425c487d8fff46d9f89310607-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF3.gif)

程序如下：
```C++
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // 将队列反过来
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        // 把最后一项拿出来
        int r = q.front();
        //删掉
        q.pop();

        // 将队列再反回来
        for (int i = 0; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }

        return r;
    }
    
    /** Get the top element. */
    int top() {
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        // 把最后一项拿出来
        int r = q.front();
        q.pop(); 
        // 再放回去最后面
        q.push(r);
        
        // 将队列再反回来
        for (int i = 0; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }

        return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};
```
