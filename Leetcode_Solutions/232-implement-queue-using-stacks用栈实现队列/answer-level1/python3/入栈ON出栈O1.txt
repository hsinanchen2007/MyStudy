### 解题思路
1、使用两个栈，第一个就是最终的队列形式，第二个用于倒腾；
2、入队为ON，出队为O1；
3、python的list，pop会删除最后一个元素即栈顶，但注意判断有值才可以Pop；
4、python的append就是往尾部添加元素；

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 入队为ON，出队为O1
        # 这是最终的样式，就是一个队列了
        self.final = []
        # 这是临时栈，用于倒腾
        self.tmp = []
        # 队列头元素


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        # 先把final的都出栈，入栈到tmp
        while len(self.final)>0:
            self.tmp.append(self.final.pop())
        # 新元素入final
        self.final.append(x)
        # 把tmp的都出栈，压入final
        while len(self.tmp)>0:
            self.final.append(self.tmp.pop())


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.final.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        front = self.final.pop()
        self.final.append(front)
        return front


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.final)==0



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```