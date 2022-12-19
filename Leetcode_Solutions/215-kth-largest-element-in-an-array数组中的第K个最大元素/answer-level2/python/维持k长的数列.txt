### 解题思路
从k+1：end，若有数>min(k长数列)，替换掉最小的，直到结尾，返回k长数列里的最小的

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if len(nums)<k:
            return None
        tmp=nums[:k]
        for i in nums[k:]:
            if i > min(tmp):
                tmp[tmp.index(min(tmp))]=i
            # print(tmp)
        return min(tmp)
```