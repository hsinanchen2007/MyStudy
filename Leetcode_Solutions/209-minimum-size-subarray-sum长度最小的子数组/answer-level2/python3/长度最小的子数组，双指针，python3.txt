### 解题思路
start = 0
end从1开始
索引start到end的nums累加和记为temp
如果temp<target: end += 1
否则累加start，更新temp，直到temp小于target
更新res
### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if not nums:
            return 0
        start = 0
        res = float("inf")
        if nums[0] >= s:
            return 1
        temp = nums[0]
        for end in range(1,len(nums)):
            if nums[end] >= s:
                return 1
            temp += nums[end]
            if temp < s:
                continue
            while temp >= s:
                temp -= nums[start]
                start += 1
                if start == end:
                    break
            res = min(res, end-start+2)
        if res == float("inf"):
            return 0
        return res
                
```