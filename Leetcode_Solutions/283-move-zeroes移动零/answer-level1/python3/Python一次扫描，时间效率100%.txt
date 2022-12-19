
![image.png](https://pic.leetcode-cn.com/ba96e7ff8761ca2c7e9e5b4a4cef45efb074c23cf9bdf3b8957d2961bf426ba0-image.png)
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i =0
        num = 0
        while i <= len(nums) -1 - num:
            if nums[i] ==0:

                del nums[i]
                nums.append(0)
                num +=1
            else:
                i +=1
```
