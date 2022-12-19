### 解题思路
代码参考了题解中的@joejoejoewu的解法，思路很简单，就是重复用append和pop的操作。
1、队列的基础概念：
![队列.png](https://pic.leetcode-cn.com/d8b4cbbbf4bd9059a169e3163d4764fd26d162651e67804b50d1cd34010b3016-%E9%98%9F%E5%88%97.png)

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intdata = []
        self.outdata = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.intdata.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.outdata)==0:
            while len(self.intdata)>0:
                self.outdata.append(self.intdata.pop())

        return  self.outdata.pop()



    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.outdata)==0:
            while len(self.intdata)>0:
                self.outdata.append(self.intdata.pop())
        
        return self.outdata[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        # return len(self.intdata)==0 and len(self.outdata)==0
        if len(self.intdata)==0 and len(self.outdata)==0:
            return True
        else:
            return False





# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```