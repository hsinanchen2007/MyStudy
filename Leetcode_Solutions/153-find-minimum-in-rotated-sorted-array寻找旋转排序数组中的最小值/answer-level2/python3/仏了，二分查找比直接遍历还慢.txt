二分查找：

![image.png](https://pic.leetcode-cn.com/70e2cd31504f5958955105ebf32e1929bd00f46da0d4ea30f013e82fb441f708-image.png)

```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        i,j=1,len(nums)-1
        while i<=j:
            k=(i+j)//2
            if nums[k]>nums[-1]:
                i=k+1
            elif nums[k]>nums[k-1]:
                j=k-1
            else:
                return nums[k]
        return nums[0]
```

直接遍历：

![image.png](https://pic.leetcode-cn.com/8892ce57a628390060168bd601553324065a56d2ac929b78ae53c1c666a49418-image.png)

```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(1,n):
            if nums[i]<nums[i-1]:
                return nums[i]
        return nums[0]
```
