### 解题思路
对于给定数组的区间最值问题首先想到的就是单调栈或者单调队列，至于用哪个得看具体题目的区间生成过程，比如这道题，显然是用单调队列。下面代码给出了Python单调队列和队列的实现，很简单，可以自己实现一下，当然也可以用Python模块中提供的数据结构。
关于单调队列和单调栈的一些介绍和应用，推荐这篇博客：[单调队列和单调栈详解](https://blog.csdn.net/u011893609/article/details/78806089)

### 代码

```python
class MonotonicQueue:
    def __init__(self):
        self.deque = []

    def push(self, x):
        while not self.is_empty() and x > self.deque[-1]:
            del self.deque[-1]
        self.deque.append(x)

    def pop(self):
        if self.is_empty():
            raise Exception('deque is empty')
        del self.deque[0]

    def top(self):
        if self.is_empty():
            raise Exception('deque is empty')
        return self.deque[0]

    def is_empty(self):
        if len(self.deque) == 0:
            return True
        return False

class Queue:
    def __init__(self):
        self.queue = []

    def push(self, x):
        self.queue.append(x)

    def pop(self):
        if self.is_empty():
            raise Exception('deque is empty')
        del self.queue[0]

    def top(self):
        if self.is_empty():
            raise Exception('deque is empty')
        return self.queue[0]

    def is_empty(self):
        if len(self.queue) == 0:
            return True
        return False

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if nums == []:
            return []
        mqueue = MonotonicQueue()
        queue = Queue()
        for i in range(k):
            mqueue.push(nums[i])
            queue.push(nums[i])
        res = []
        q = k - 1
        while True:
            res.append(mqueue.top())
            if mqueue.top() == queue.top():
                mqueue.pop()
            queue.pop()
            q += 1
            if q == len(nums):
                break
            mqueue.push(nums[q])
            queue.push(nums[q])
        return res
```