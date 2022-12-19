### 解题思路
1.删除不需要的————del
2.添加nums2————append
3.排序————sort()

### 代码

```python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        for i in range(len(nums1)-1,m-1,-1):
            del nums1[i]
        for i in range(len(nums2)):
            nums1.append(nums2[i])
        return nums1.sort()
        
```