### 解题思路
（大三下学期 + 暑假）几年前在网上看到了一个解决此问题的优秀博客，记忆犹新。并且和 xubo 讨论过此。

官方题解 1 有点出乎我的意料，完全是借助 L2 来保持 L1 中元素的顺序的有效性。但复杂度有些高 O(n)
而解法 2 平摊分析 O(1)。

我下面的想法稍微改进了官方题解2的解法：

设有栈 L1, L2, 维持如下状态：L1 中的元素与L2中的元素恰好顺序相反（两次先入后出 = 先入先出）。每次入元素，都往 L1 里面装，且变量 n += 1。当要出元素时，检查 L2 是否为空，若 L2 不为空，则返回 L2 的一个元素, n-=1 ; 若 L2 为空，则从 L1 中倒出 n-1 个元素到 L2 中，然后返回 L1 的最后一个元素，n-= 1。

注意这个 n -= 1 的 code 的实现不要出错。

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.L1 = []
        self.L2 = []
        self.n = 0 # 当前元素个数


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """

        self.L1.append(x)
        self.n += 1


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.n == 0:
            return None
        
        #self.n -= 1  # bug, 下面还要用到 self.n

        if self.L2:  # bug not self.L2, 当前 L2 非空, 总是多加了一个 not
            self.n -= 1
            return self.L2.pop()
        else:
            for _ in range(self.n - 1):
                self.L2.append(self.L1.pop())
            self.n -= 1
            return self.L1.pop()
        # self.n -= 1  # bug 在return 语句后面不会执行

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.n == 0:  # Error
            return None

        if self.L2:  # 当前 L2 非空
            return self.L2[-1]
        else:
            for _ in range(self.n):  # bug n-1, 这里应该是 n
                self.L2.append(self.L1.pop())
            return self.L2[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.n == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```