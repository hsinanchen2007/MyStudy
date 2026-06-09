### 解题思路
$python$ 没有队列的结构，可以使用双端队列 $deque$来实现。

### 代码

```python []
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = collections.deque() # 初始化


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if not self.stack:
            return None
        return self.stack.pop() # pop 队尾元素
        

    def top(self) -> int:
        """
        Get the top element.
        """
        if not self.stack:
            return None
        return self.stack[-1] # 返回队尾元素
        


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.stack
```


PS：想要一起努力的童鞋们可以关注我的公众号：腐烂的橘子，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋