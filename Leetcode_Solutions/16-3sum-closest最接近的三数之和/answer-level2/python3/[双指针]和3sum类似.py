### 解题思路
和3sum一样的思路

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        res_v = 2147483647
        res = []
        for inda, a in enumerate(nums[:-2]):
            ib, ic = inda+1, len(nums)-1
            while ib < ic:
                vb, vc = nums[ib], nums[ic]
                if abs((a + vb + vc) - target) < res_v:
                    res = [a, vb, vc]
                    res_v = abs((a + vb + vc) - target)
                if vb + vc + a < target:
                    ib += 1
                elif vb + vc + a > target:
                    ic -= 1
                else:
                    return target
        return sum(res)

```