### 解题思路
始终保持python双端队列左端元素为窗口最大值, 元素从右端写进去

### 代码

```python3
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # 设置双端队列头部为左端, 左端保持最大值, 方便取值; 尾部为右端
        q = deque()
        window = []
        for i, n in enumerate(nums):
            while q and q[0] < i - k + 1:
                q.popleft()
            
            while q and nums[q[-1]] < n:
                q.pop()

            q.append(i)
            
            # 前k-1个数先不要放值, 之后再依次放
            if i >= k - 1:
                window.append(nums[q[0]])

        return window


```