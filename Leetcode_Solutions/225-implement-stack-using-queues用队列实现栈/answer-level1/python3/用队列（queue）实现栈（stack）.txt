### 解题思路
先比较队列和栈的区别，再考虑如何转换。
队列：先进先出
push():从队尾进
pop():从队首出
top():从队首看
empty():判断是否为空

栈：先进后出
push():从栈首进
pop():从栈首出
top():从栈首看
empty():判断是否为空

可以看到pop()、top()和empty()是一样的。我们要改进push()方法，我们把要push的元素x先push进队列里，这时候x在队尾，但是x应该先出，因此x要被放到队首。那就把x之前的元素全部push到队尾。这样就用队列实现了栈。

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue=[]

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        n=len(self.queue)
        self.queue.append(x)
        for i in range(n):
            p=self.queue[0]
            self.queue.remove(self.queue[0])
            self.queue.append(p)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.empty():
            return False
        else:
            p=self.queue[0]
            self.queue.remove(self.queue[0])
            return p

    def top(self) -> int:
        """
        Get the top element.
        """
        if self.empty():
            return False
        else:
            return self.queue[0]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.queue==[]
```