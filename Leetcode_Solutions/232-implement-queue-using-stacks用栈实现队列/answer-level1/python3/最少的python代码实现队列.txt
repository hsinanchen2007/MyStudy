# **方法一：只用一个列表**

由于python中没有栈，因此只能用list代替
对于push()操作，无需关心内部的是什么，只用保证压进去了就行
对于pop()  保证先进先出即可


**总结** :
1.熟悉使用列表的append、pop()、list[-1]三种操作就可以了。
2.无论是队列也好，栈也罢，只要实现物理逻辑就行
3.题目并没有对时间复杂度提出要求，因此实现功能就可
```
class MyQueue:
    def __init__(self):
        self.s = []
    def push(self, x: int) -> None:
        self.s.append(x)
    def pop(self) -> int:    
        return self.s.pop(0)
    def peek(self) -> int:
        return self.s[0]
    def empty(self) -> bool:
        return not bool(self.s)
```

## **方法二：经常看到的双列表实现队列**
```
class MyQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, x: int) -> None:
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        self.stack1.append(x)
        while self.stack2:
            self.stack1.append(self.stack2.pop())
    def pop(self) -> int:
        return self.stack1.pop()
    def peek(self) -> int:
        return self.stack1[-1]
    def empty(self) -> bool:
        return not bool(self.stack1)
```
