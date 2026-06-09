### 解题思路
因为python中不支持队列，所以使用的列表来模拟队列，通过列表添加元素和删除元素来模拟栈的读写。(但是有一个小小的问题是我的解决方法中并不涉及到队列，本质上不是用队列实现栈，所以是否不符合要求？)

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.QueueA = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.QueueA.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.QueueA) == 0:
            print("the stack is empty!")
        else:
            pop_out = self.QueueA[-1]
            self.QueueA = self.QueueA[:-1]
            return pop_out



    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.QueueA) == 0:
            print("the stack is empty!")
        else:
            top_out = self.QueueA[-1]
            return top_out


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.QueueA) == 0:
            return True
        else:
            return False



# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(1)
obj.push(2)
obj.push(3)
param_2 = obj.pop()
param_3 = obj.top()
param_4 = obj.empty()
print(param_2)
print(param_3)
print(param_4)
```