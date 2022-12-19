### 解题思路
法1：单向队列，front模拟栈的top指针。所以出栈即为出队列，入栈时，序列逆转。
![TIM图片20200301232506.jpg](https://pic.leetcode-cn.com/6c3bf24bd8245671fb8fbe10af2887a7a548bf26d1b54af5059848688472e7f2-TIM%E5%9B%BE%E7%89%8720200301232506.jpg)
法2：双向队列。简直是作弊，直接对front一顿操作。
法2：双队列，思想同单向队列，只不过在逆转的时候借助了另一个队列，代码不再赘述。
### 代码

```cpp
//法1：单向队列实现栈
class MyStack {
private:
    queue<int> qs;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        int size = qs.size();
        int temp;
        qs.push(x);
        while (size--) {//把序列逆转
            temp = qs.front(); 
            qs.pop();
            qs.push(temp);
        }

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = qs.front();
        qs.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        return qs.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qs.empty();
    }
};

//法2：双向队列实现栈
class MyStack {
private:
    deque<int> qs;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        qs.push_front(x);

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = qs.front();
        qs.pop_front();
        return top;
    }

    /** Get the top element. */
    int top() {
        return qs.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qs.empty();
    }
};

```

![12.png](https://pic.leetcode-cn.com/ee0293d6dc8b2855a1a7ad624ed53bc9286ee473c30ffa0c13f1f499e90cdfdf-12.png)

效率都不高...
