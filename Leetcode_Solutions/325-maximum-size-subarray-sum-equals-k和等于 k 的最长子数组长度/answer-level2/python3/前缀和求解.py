### 解题思路
基本思路为：
- 计算前缀和
- 对当前的前缀和`cur_sum`，向前面找是否存在`cur_sum -k`，存在则更新ans
- 如果`cur_sum`不在`pre`中，将`cur_sum`加入（如果存在，前面的坐标更小，不需更新）


### 代码

```python3
from itertools import accumulate


class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        pre = {0: -1}
        ans = 0
        for index, cur_sum in enumerate(accumulate(nums)):
            if cur_sum - k in pre:
                ans = max(ans, index - pre[cur_sum - k])
            if cur_sum not in pre:
                pre[cur_sum] = index
        return ans

```