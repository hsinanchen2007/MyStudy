### 解题思路
和三数之和，四数之和类似。双指针+当前元素 

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        #双指针L/R/i
        #special case
        if len(nums)<3:return 0
        if len(nums)==3:return nums[0]+nums[1]+nums[2]
        res=float('inf')
        #1.数组排序
        nums.sort()
        #2.遍历
        for i in range(len(nums)-2):
            L=i+1
            R=len(nums)-1#初始化L/R
            while L<R:
                sumcum=nums[i]+nums[L]+nums[R]
                if sumcum-target==0:return sumcum
                elif sumcum-target>0:
                    if abs(res-target)>abs(sumcum-target):res=sumcum
                    R-=1
                else:
                    if abs(res-target)>abs(sumcum-target):res=sumcum
                    L+=1
        return res
```