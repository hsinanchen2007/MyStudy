### 解题思路
作者：百里奚
![image.png](https://pic.leetcode-cn.com/150208efb14c0053398ea1ae69161f83db8d0a7b95443fd70b3bd2b44e84dbe9-image.png)

### 代码

```python3
class RecentCounter:
    # 作者：LeetCode
    def __init__(self):
        self.queue = collections.deque()

    def ping(self, t: int) -> int:
        self.queue.append(t)
        while self.queue[0] < t - 3000:
            self.queue.popleft()  # 删除队头元素
        return len(self.queue)
        
# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```