### 解题思路
此处撰写解题思路
先建一个m+n的空列表a
从头比较两个列表的第一个元素大小，小的加入空列表a并下标向后移一位，直到一个列表遍历完
把另一个列表剩余部分并入a
a就是一个有序列表
直接返回a的中位数
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a=[]
        i=j=0
        while(i<len(nums1) and j<len(nums2)):
            if(nums1[i]<=nums2[j]):
                a.append(nums1[i])
                i=i+1
            else:
                a.append(nums2[j])
                j=j+1
        if(j<len(nums2)):
            a.extend(nums2[j:])
        if(i<len(nums1)):
            a.extend(nums1[i:])
        b=len(a)
        if(b%2==0):
            return float("{0:.1f}".format(((a[int(b/2)-1]+a[int(b/2)])/2)))
        else:
            return float("{0:.1f}".format(a[int(b/2)]))
```