### 解题思路
思路很简单：
首先将两个数组合并成一个从小到大排列的数组，因为原本的两个数组就是有序的，所以这一不步很简单；大家看一下我写的代码应该都能看懂
接下来就是计算中位数了；
根据题目介绍可知，当两个数组元素之和为奇数时，返回中间的元素即可；
当两个数组元素个数为偶数时，返回的是z中间两个元素的平均值；

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        lens1 = len(nums1)
        lens2 = len(nums2)
        i = 0
        j = 0
        '合并数组'
        merge = []
        while i<lens1 and j<lens2:
            if nums1[i] < nums2[j]:
                merge.append(nums1[i])
                i += 1
            elif nums1[i] > nums2[j]:
                merge.append(nums2[j])
                j += 1
            elif nums1[i] == nums2[j]:
                merge.append(nums1[i])
                merge.append(nums2[j])
                i += 1
                j += 1
        
        if i < lens1:
            for j in range(i,lens1):
                merge.append(nums1[j])
        elif j < lens2:
            for i in range(j,lens2):
                merge.append(nums2[i])
    
         
        '查找中位数'
        if (lens1+lens2)%2 == 0:
            mid = (lens1+lens2)/2
            mid = int(mid)
            ans = (merge[mid-1] + merge[mid])/2
        elif (lens1+lens2)%2 ==1:
            mid = (lens1+lens2)//2
            mid = int(mid)
            ans = merge[mid]
        
        return ans
        
```