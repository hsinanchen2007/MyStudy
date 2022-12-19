### 解题思路
时间复杂度和快排一样O(nlogn)
![image.png](https://pic.leetcode-cn.com/9b5ed93f138a6b2d5a9ecf7861f0cc79210dc5f3fe1d2d5cfefecb809d78e09a-image.png)
### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        # qsort 变形
        if not nums:
            return ''
        if len(nums) == 1:
            return str(nums[0])
        def qsort(nums=nums):
            if not nums:
                return []
            if len(nums) == 1:
                return nums

            mid = len(nums) // 2
            L = []
            R = []
            for i, num in enumerate(nums):
                if i == mid:
                    continue                
                if int(str(nums[mid]) + str(num)) >= int(str(num) + str(nums[mid])):
                    L.append(num)
                else:
                    R.append(num)

            res = qsort(L) + [nums[mid]] + qsort(R)
            return res
        res = qsort()
        return ''.join(list(map(str, res)))

                           
```