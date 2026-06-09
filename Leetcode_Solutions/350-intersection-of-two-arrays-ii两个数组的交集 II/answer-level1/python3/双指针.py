### 解题思路
双指针
排序后从头比较两个数组，注意while条件，其中一个数组遍历到头的时候就不用比较了，

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        res=[]
        i=0
        j=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]>nums2[j]:
                j+=1
            elif nums1[i]<nums2[j]:
                i+=1
            else:
                res.append(nums1[i])
                i+=1
                j+=1
        return res
```