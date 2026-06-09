![image.png](https://pic.leetcode-cn.com/e23bb941e087b40fc27d44648aa4b6ca799a3d7fc8d5cf27d9d4b4a34a9400fd-image.png)
```
# in python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bins = {}
        for n in nums:
            try:
                bins[n] += 1
            except:
                bins[n] = 1
        for k in bins:
            if bins[k] == 1:
                return k
```



