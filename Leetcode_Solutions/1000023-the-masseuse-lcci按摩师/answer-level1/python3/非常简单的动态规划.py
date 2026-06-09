### 解题思路
利用动态规划，慢慢的加就好了，需要注意的是考虑空列表，以及最少需要隔一位元素。直接看代码吧

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        nlen = len(nums)
        alist = [0] * nlen
        if nlen == 0 :
            return 0
        for i in range(nlen):
            if i <= 1:
                alist[i] = nums[i]
            else :
                alist[i] = nums[i] + max(alist[ : i-1])
        return max(alist)
```