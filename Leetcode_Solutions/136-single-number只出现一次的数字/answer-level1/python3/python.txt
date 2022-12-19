### 解题思路
利用python函数 sort(). 对数组排序，则出现两次元素必定相邻。由于数组为单数，添加判定元素。
一次遍历，若相邻元素不相等，则为只出现一次元素


### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        nums.append(0)
        n = len(nums)
        if nums[0] == 0 and n == 1:
            return 0
        for i in range(0,n+1,2):
            if nums[i] != nums[i+1]:
                return nums[i] 
```