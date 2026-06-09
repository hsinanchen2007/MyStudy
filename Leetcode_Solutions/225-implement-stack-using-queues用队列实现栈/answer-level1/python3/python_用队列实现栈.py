### 解题思路
方法一：双队列
构造辅助对列，操作栈顶元素时，将其他元素全部转移到辅助对列中
优化：
1、使用deque容器
2、在push、pop、top时都可以使用辅助队列，个人认为在push时使用和单队列想法相似，所以选择pop时使用

### 代码
``` python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1=[]
        self.queue2=[]
        self.topElement=0



    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.append(x)
        self.topElement=x


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        for i in range (len(self.queue1)-1):
            self.topElement=self.queue1.pop(0)
            self.queue2.append(self.topElement)
        popElement=self.queue1.pop(0)
        self.queue1=self.queue2
        self.queue2=[]
        return popElement


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.topElement


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue1)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```

### 解题思路
方法二：单队列
队列先进先出，栈先进后出，其实非常相似，如果倒着保存数据，那么队列就是栈

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
        self.queue.append(x)
        for i in range (len(self.queue)-1):
            self.queue.append(self.queue.pop(0))

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.queue.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.queue[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
