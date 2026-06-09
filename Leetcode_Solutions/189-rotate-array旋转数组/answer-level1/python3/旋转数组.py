数组切片与循环的方法结合，节省空间和时间。
![image.png](https://pic.leetcode-cn.com/627c490363074d42c60eda0121877f90803ce0d4d477cc99340f3547a4029c7f-image.png)

```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k!=0:
            if k>len(nums):
                for i in range(k):
                    nums[0],nums[1:] = nums[-1],nums[0:-1]
            else:
                nums[:k],nums[k:] = nums[-k:],nums[0:-k]
```



