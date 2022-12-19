### 解题思路
首先回忆队列和栈的区别
- 队列：一端增加元素，另一端删除元素，先进先出
- 栈：仅在一段增加或删除元素，先进后出
可用的队列基本操作：**入队，出队，获取长度，判断是否为空**
此时考虑一下要实现的栈操作：
**入栈**-可以用入队解决，栈顶即队尾
**移除栈顶元素**-按照队列的规则需要把该元素之前的元素全部出队后，才能取到它。那些取出的元素可以：1.重新入队 2.放入另外一个队列。
下面是用两个队列实现的，入栈出栈都从队列1，队列2用来暂存其他元素
-----------------
来自菜鸡的第一天打卡
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue1=[]
        self.queue2=[]



    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue1.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.queue1):
            while len(self.queue1)!=1:
                self.queue2.append(self.queue1.pop(0))
            return self.queue1.pop()
        else:
            while len(self.queue2)!=1:
                self.queue1.append(self.queue2.pop(0))
            return self.queue2.pop()



    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.queue1):
            while len(self.queue1)!=1:
                self.queue2.append(self.queue1.pop(0))
            res=self.queue1.pop()
            self.queue2.append(res)
            return res
        else:
            while len(self.queue2)!=1:
                self.queue1.append(self.queue2.pop(0))
            res=self.queue2.pop()
            self.queue1.append(res)
            return res


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.queue1)==0 and len(self.queue2)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```