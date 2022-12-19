### 解题思路
日常动态规划

### 代码
![截屏2020-03-2422.32.33.png](https://pic.leetcode-cn.com/ac72080c07a0a9925aac56323386914ae5d4acde1ab392657266e6c56522e927-%E6%88%AA%E5%B1%8F2020-03-2422.32.33.png)
```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        nums.append(0)
        l = len(nums)
        for i in range(2, l):
            nums[i] = max(nums[i]+nums[i-2], nums[i]+nums[i-3])
        return max(nums)
```