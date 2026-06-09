### 解题思路
- 暴力搜索枚举是 `O(n^3)`;
- 排序后查找：`O(n^2)`：
  - 有序数组中一对数之和 -> `O(n)`
  - 如何排除重复：在枚举过第一个数a后相同为a对数，要不要再查找一遍？

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set([])
        nums = sorted(nums)
        for aind,a in enumerate(nums[:-2]):
            if a > 0:
                break
            elif aind > 0 and nums[aind] == nums[aind-1]:
                continue
            else:
                target = 0 - a
                il, ir = aind+1, len(nums)-1
                while il < ir:
                    vl, vr = nums[il], nums[ir]    
                    if vl > target:
                        break
                    else:
                        if vl + vr < target:
                            il += 1
                        elif vl + vr > target:
                            ir -= 1
                        else:
                            res.add(tuple([a, vl, vr])) 
                            il += 1
                            ir -= 1
                            while nums[il-1] == nums[il] and il < ir:
                                il += 1
                            while nums[ir+1] == nums[ir] and il < ir:
                                ir -= 1 
                            # print(il, ir)
        return res
```