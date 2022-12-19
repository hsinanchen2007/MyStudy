### 解题思路
整个问题的难点在于理清队列和栈的区别
队列：先进先出
栈：先进后出

只需要逻辑上实现先进后出的功能就行
详解见 图片
![搜狗截图20200323170641.jpg](https://pic.leetcode-cn.com/8fedbbd63e6ab250af320862a0ef92a3eb06e5f4b190f43d2a10d0d5f95ad587-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20200323170641.jpg)

### 代码

```cpp
class MyStack {
public:
    
    MyStack() {}
    
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(!m_s.empty())
        {
            temp.push(m_s.front());
            m_s.pop();
        }
        while(!temp.empty())
        {
            m_s.push(temp.front());
            temp.pop();
        }
    }
    
    
    int pop() {
        int x=m_s.front();
        m_s.pop();
        return x;

    }
    
    
    int top() {
        return m_s.front();
    }
    
   
    bool empty() {
        return m_s.empty();
    }
private:
    queue<int> m_s;
};
```