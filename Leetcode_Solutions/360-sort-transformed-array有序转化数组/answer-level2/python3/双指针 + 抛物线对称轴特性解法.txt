### 解题思路
找出距离中轴线最远的点，计算出结果先append进列表；
若是a>0,抛物线开口向上，离的越远，值越大，结果需要倒序
若是a<0,抛物线开口向下，离得越远，值越小，直接return
若是a=0,再根据b的情况具体分析，这里比较简单，不再细说

### 代码

```python3
class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        if not nums: return []
        res, size = [], len(nums)
        if a == 0:
            if b == 0:
                return [c for _ in range(size)]
            elif b > 0:
                return [b * x + c for x in nums]
            else:
                return [b * x + c for x in nums[::-1]]
        mid = -b / 2 / a
        l, r = 0, size - 1
        while l <= r:
            x = 0
            if abs(nums[r] - mid) > abs(nums[l] - mid):
                x = nums[r]
                r -= 1
            else:
                x = nums[l]
                l += 1
            res.append(a * x * x + b * x + c)
        return res if a < 0 else res[::-1]
```