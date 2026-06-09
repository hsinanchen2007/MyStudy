刚实话，都差不多。

一行版

![image.png](https://pic.leetcode-cn.com/515c17fe84bde12f560e02ce55445729f75a5ded1680810a0e97772949ce730f-image.png)

```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        return target in nums
```

找出旋转点，再二分查找版

![image.png](https://pic.leetcode-cn.com/ea58f75b4882d2f45747c7d71f5c34234aadfc874a8d74d612d902388442b4b1-image.png)


```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        n=len(nums)
        m=-1#旋转点标记
        for i in range(1,n):
            if nums[i]<nums[i-1]:
                m=i-1
                break
        i,j=0,n-1
        if m!=-1:
            if target>nums[m] or target<nums[m+1]:
                return False
            elif target>nums[-1]:
                j=m
            elif target<nums[-1]:
                i=m+1
            else:
                return True
        while i<=j:
            k=(i+j)//2
            if target>nums[k]:
                i=k+1
            elif target<nums[k]:
                j=k-1
            else:
                return True
        return False
```
