### 解题思路
交换是指：尝试把尽可能低位上的数字和它右边一个更大数字交换
排序: 然后把这个交换的数字右侧的数组排成升序

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = len(nums) - 2
        minv = nums[n-1]
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
        j = n - 1
        while j > i:
            if nums[j] > nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
                while True:
                    f = True
                    k = i + 1
                    while k < n - 1:
                        if nums[k] > nums[k+1]:
                            nums[k], nums[k+1] = nums[k+1], nums[k]
                            f = False
                        k += 1
                    if f: 
                        return
            j -= 1
        nums.sort()

```

欢迎来我的博客： https://codeplot.top/
我的博客刷题分类：https://codeplot.top/categories/%E5%88%B7%E9%A2%98/