### 解题思路
用一个主栈和辅助栈
保证辅助栈栈顶是最小元素
因此返回辅助栈栈顶即可
### 代码

```java
class MinStack {
    private Stack<Integer> s1;
    private Stack<Integer> s2;
    /** initialize your data structure here. */
    public MinStack() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    
    public void push(int x) {
        s1.add(x);
        if (s2.empty() || s2.peek()>x){
            s2.add(x);
        }
        else{
            s2.add(s2.peek());
        }
    }
    
    public void pop() {
        s1.pop();
        s2.pop();

    }
    
    public int top() {
        return s1.peek();
    }
    
    public int min() {
        return s2.peek();

    }
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```
```
# python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []  # 主栈，用于存储元素
        self.min_stack = []  # 辅助栈，栈顶存储最小值


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)  # 入栈
        if not self.min_stack: # 辅助栈为空 加入x
            self.min_stack.append(x)
        else:  # 不为空 进行比较
            if self.min_stack[-1] < x:  # 保证B中是最小的元素
                self.min_stack.append(self.min_stack[-1])
            else:
                self.min_stack.append(x)

    def pop(self):
        """
        :rtype: None
        """
        # 同时弹出
        self.stack.pop()  # 弹出栈顶元素
        self.min_stack.pop()  # 删除栈顶元素在辅助栈的备份

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:  # 不为空 返回主栈栈顶即可
            return []
        else:
            return self.stack[-1]


    def min(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]

```
