* 最初用的方法：
    * 如果这次能跳到最后一步，跳！
    * 如果不能，就跳到能让它下次跳的最远的距离
* 但是时间复杂度不稳定

```python []
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        res = 0
        m = len(nums)
        i = 0 # 绝对位置
        while(True):
            far = 0 # 相对i的位置
            next_i = i
            for j in range(1, nums[i]+1):  # 相对i的位置
                if (i+j >= m-1):
                    res += 1
                    return res
                if (j + nums[i+j] > far):
                    far = j + nums[i+j]
                    next_i = i+j
            i = next_i
            res += 1
```

* 这个方法一次for循环即可。
```python []
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums)<2:
            return 0
        end, maxpos, res = 0, 0, 0
        for i in range(len(nums)):
            maxpos = max(maxpos, i + nums[i])
            if maxpos >= len(nums) - 1:
                res += 1
                break
            if i == end:
                end = maxpos
                res += 1
        return res
```