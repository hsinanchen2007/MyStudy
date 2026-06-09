### 解题思路
此处撰写解题思路

### 代码

```python3
'''
#top与pop取出队列最后一个
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q=queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.Q.push(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        tmp=queue()
        while self.Q.size()!=1:
            tmp.push(self.Q.pop())
        res=self.Q.pop()
        self.Q=tmp
        return res
        

    def top(self) -> int:
        """
        Get the top element.
        """
        tmp=queue()
        while self.Q.size()!=1:
            tmp.push(self.Q.pop())
        res=self.Q.pop()
        tmp.push(res)
        self.Q=tmp
        return res

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.Q.is_empty()
'''
#push时候改变队列存储顺序
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q=queue()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        tmp=queue()
        tmp.push(x)
        while self.Q.size():
            tmp.push(self.Q.pop())
        self.Q=tmp

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.Q.pop()
        
    def top(self) -> int:
        """
        Get the top element.
        """
        return self.Q.top()

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.Q.is_empty()

#队列
class queue:
    def __init__(self):
        self.L=[]
        self.c=0
    def push(self,x):
        self.L.append(x)
        self.c+=1
    def top(self):
        if self.c:
            return self.L[0]
        else:
            return None

    def pop(self):
        if self.c:
            self.c-=1
            return self.L.pop(0)
        else:
            return None
    def size(self):
        return self.c

    def is_empty(self):
        return not bool(self.c)

            

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```