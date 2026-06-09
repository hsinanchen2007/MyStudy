### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:

        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1,0,-1):
            if nums[i] > nums[i-1]:
                tem_num = nums[i:]
                tem_num.sort()
                nums[i:] = tem_num
                for j in range(i,len(nums)):
                    if nums[j] > nums[i-1]:
                        nums[j],nums[i-1] = nums[i-1],nums[j]
                        break
                return
        nums.sort()
```



reference the solution from the author Déjà vu,

that is very nice 