### 解题思路
由奇数的idx组成滑动窗口的左右边界，并且保证窗口中有且仅有k个奇数。
### 代码
窗口从头开始或者到达最后一个idx的特殊情况分开处理：
```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        idx = [i for i in range(len(nums)) if nums[i]%2]
        if len(idx) < k: return 0
        res = 0
        for i in range(k-1, len(idx)):
            if i == k-1:
                l = idx[i-k+1]+1
            else:
                l = idx[i-k+1] - idx[i-k] 
            if i == len(idx) - 1:
                r = len(nums) - idx[i]
            else:
                r = idx[i+1] - idx[i] 
            res += l * r
        return res
```
提前加入适当的虚拟idx用来处理边界：
```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        idx = [-1] + [i for i in range(len(nums)) if nums[i]%2] + [len(nums)]
        if len(idx) < k: return 0
        res = 0
        for i in range(k, len(idx)-1):
            l = idx[i-k+1] - idx[i-k] 
            r = idx[i+1] - idx[i] 
            res += l * r
        return res
```


