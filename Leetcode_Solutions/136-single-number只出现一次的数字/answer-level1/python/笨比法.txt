### 解题思路
作弊方法。。先sort排序后直接两个两个对比是否相等
遍历一遍数组，复杂度O(n)

![QQ截图20200319213117.png](https://pic.leetcode-cn.com/90da4f5dbe0f75cfec9fadf06ebe0987637d0645101d736fcbb78c885d90cd81-QQ%E6%88%AA%E5%9B%BE20200319213117.png)


### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        if len(nums) == 1: # 只有一个元素时直接返回
            return nums[0]
        if nums[-1] != nums[-2]: # 出现在末尾的特殊情况
            return nums[-1]
        for i in range(0,len(nums)-1,2):
            if nums[i] != nums[i + 1]:
                return nums[i]

```