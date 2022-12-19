### 解题思路
栈——后进先出，队列——先进先出，push可以直接使用append；pop直接使用队列的pop方法，移除最后一位即可；
top取栈顶元素，使用append在后端进入，栈顶就是队列的最后一位，使用q[-1]；
empty使用bool函数即可。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)




    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(-1)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[-1]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.q)




# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
### 但是！！！
按照栈的要求，新入栈的元素必须在第一位，所以在push函数在append之后，将先前入栈的元素放到新元素后方，也就是将新元素之前的队列元素按顺序出队列再入队列。

### 代码
```python3
class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        q_length = len(self.q)
        while q_length > 1:
            self.q.append(self.q.pop(0))
            q_length -= 1


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.q)

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
虽然两种都通过了！！！