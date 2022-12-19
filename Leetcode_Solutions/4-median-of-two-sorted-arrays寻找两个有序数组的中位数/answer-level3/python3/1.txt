### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        for num in nums1:
            num=float(num)
        for num in nums2:
            num=float(num)

        if (len(nums1)+len(nums2))%2==0:
            ou=1#是偶数
        else:
            ou=0#是奇数

        sum_num=nums1+nums2
        sum_num.sort()


        if ou==1:
            result=(float(sum_num[int(len(sum_num)/2)]+sum_num[int((len(sum_num)/2)-1)])/2)
        if ou==0:
            result=sum_num[int(len(sum_num)/2)]
        return result
```