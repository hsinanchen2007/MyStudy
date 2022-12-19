### 解题思路

朴素的思想是，先求解前缀和，然后两层循环，直接求解即可

但是这样做会TLE，想方法优化。 可以先将[0, i-1]的所有前缀和的各种情况用字典存储起来，在遍历到i时，

直接判断t - nums[i] 在以前的前缀和中出想过几次即可。

时间复杂度`O(n)`， 空间复杂度`O(n)`

### 代码

```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        t = {0:1}
        s = 0
        res = 0
        for x in nums:
            s += x
            if s - k in t:
                res += t[s-  k]
            if s in t:
                t[s] += 1
            else:
                t[s] = 1
        
        return res
```