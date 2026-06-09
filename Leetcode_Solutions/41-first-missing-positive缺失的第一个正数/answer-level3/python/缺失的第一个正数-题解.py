### 解题思路
思路有点暴力：
- 缺失的第一个正数，要么是最小，要么是最大；
- 对于负数和0来说，都可以忽略；
- 所以，暴力想法就是，从1开始，直接遍历到数组中的最大值；
- 哪一个没有出现在[1,max]中，哪一个就是要寻找的缺失的第一个正数；
- 如果最大数小于等于0，则说明缺失的第一个正数是1；
- 如果遍历之后仍然没有找到，则说明最大值+1是那个缺失的正数；

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums:
            return 1
        imax = max(nums)
        if imax < 1:
            return 1
        rst = 0
        for i in range(1, imax):
            if i not in nums:
                rst = i
                break
        if rst == 0:
            rst = max(imax+1, 1)
        return rst
```