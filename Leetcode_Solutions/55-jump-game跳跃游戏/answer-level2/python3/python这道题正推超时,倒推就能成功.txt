### 解题思路
这题采用动态规划,思路看这里https://www.bilibili.com/video/av47420469?from=search&seid=7335933815712595819


### 代码

```python3
import functools
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        size = len(nums)
        cache_size = size %2 ==0 and size or size+1
        sizeM1 = size-1
        @functools.lru_cache(cache_size)
        def f(pos):
            if pos <=0:
                return True
            for i in range(pos-1, -1, -1):
                if nums[i] + i >= pos:
                    return f(i)
            return False

        return f(sizeM1)

```