### 解题思路
因为需反复操作：
- 将新的数据加入到窗口尾部
- 将旧的数据从窗口头部删除
所以用双端队列（double-ended queue)表示窗口，能在O(1)时间内完成以上操作

注意：队列中储存的都是元素对应的index
队列中head是当前窗口（k个元素）的最大值的index
While 当前元素>tail：弹出tail
将该元素放至tail
每次读取head的nums值，append至输出list中

在python中实现queue
- 方法1：用collections.deque
```python
from collections import deque
q = deque()
q.append(x) # enqueue
q.popleft() # dequeue
# 双端 多的操作：
q.appendleft(x) # 将x加至head
q.pop() # 移除tail
```
- 方法2（采用）：直接用list[]
```python
q = []
q.append() # enqueue
q.pop(0) # dequeue
# 双端 多的操作：
q.insert(0, x) # 将x加至head
q.pop() # 移除tail
```

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # special case: nums=[] or k==1
        if not nums or k==1: return nums
        # normal cases:
        ans = []
        n = len(nums)
        q = [0]
        for i in range(1, k-1):
            while q and nums[i] > nums[q[-1]]:
                q.pop()
            q.append(i)
        for i in range(k-1, n):
            if i-q[0] > k-1: q.pop(0)
            while q and nums[i] > nums[q[-1]]:
                q.pop()
            q.append(i)
            ans.append(nums[q[0]])
        return ans
```