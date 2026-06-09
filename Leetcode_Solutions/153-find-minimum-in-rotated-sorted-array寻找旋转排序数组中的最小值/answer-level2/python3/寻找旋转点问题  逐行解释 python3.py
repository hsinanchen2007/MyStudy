# 题解
利用排序数组的特性，最小值一定是旋转点。本题和[33.搜索旋转排序数组 Leetcode](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/er-fen-cha-zhao-fa-zhong-dian-zai-yu-bian-jie-zhu-/)非常相似。[33.搜索旋转排序数组 CSDN](https://blog.csdn.net/zhushaojiecumt/article/details/102872442)
都是使用二分查找法，寻找旋转点的索引。
## 二分法
 1. 特判，若$nums$为空，则返回$None$。若长度为$1$，返回$nums[0]$。
 2. 初始化左指针$l=0$和右指针$r=n-1$。
 3. 若$nums[l]<nums[r]$，说明未旋转，返回$nums[0]$
 4. 循环条件$l<=r$，接下来有两种写法，**注意边界**：
  	+ $rotate=(l+r)//2$，如果$nums[rotate]<nums[rotate-1]$,此时返回$nums[rotate]$，判断是否满足$nums[rotate]>nums[r]$，若满足说明旋转点在右端，令$l=rotate+1$,否则在左端，令$r=rotate-1$。
 	+ $rotate=(l+r)//2$，如果$nums[rotate]>nums[rotate+1]$,此时返回$nums[rotate+1]$，判断是否满足$nums[rotate]<nums[l]$，若满足说明旋转点在左端，令$r=rotate-1$,否则在右端，令$l=rotate+1$。



### 复杂度分析
 - 时间复杂度：$O(log(n))$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if(not nums):
            return None
        n=len(nums)
        if(n==1):
            return nums[0]
        l=0
        r=n-1
        if(nums[l]<nums[r]):
            return nums[0]
        while(l<=r):
            rotate=(l+r)//2
            if(nums[rotate]>nums[rotate+1]):
                return nums[rotate+1]
            elif(nums[rotate]<nums[l]):
                r=rotate-1
            else:
                l=rotate+1
```