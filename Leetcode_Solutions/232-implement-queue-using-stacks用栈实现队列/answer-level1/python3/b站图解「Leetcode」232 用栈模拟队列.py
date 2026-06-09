## 点击播放
[![点击播放](https://pic.leetcode-cn.com/97bc04e862a5734e93b8898460568d2b807d96bab87c7d473f6103fcdba139db-232%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.PNG)](https://www.bilibili.com/video/av86054613/)



```
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.A = []
        self.B = []
        
    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.A.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.empty():
            return
        if len(self.B) == 0:
            while len(self.A) != 0:
                self.B.append(self.A.pop())
            return self.B.pop()
        else:
            return self.B.pop()
        
    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.empty():
            return
        if len(self.B) == 0:
            while len(self.A) != 0:
                self.B.append(self.A.pop())
            return self.B[-1]
        else:
            return self.B[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.B)==0 and len(self.A)==0:
            return True
        else:
            return False
```

更多Leetcode刷题图解、大数据、机器学习、推荐系统方面资源分享，可以关注B站up主：[BigDataLook](https://space.bilibili.com/95630530)

