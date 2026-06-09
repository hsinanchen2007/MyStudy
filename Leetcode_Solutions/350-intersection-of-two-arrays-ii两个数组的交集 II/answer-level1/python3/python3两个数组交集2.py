### 解题思路
先对两数组进行排序，其次使用两个指针分别指向两个数组比较的值，一次遍历。

### 代码
```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        res=[]
        i=0
        j=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]==nums2[j]:
                res.append(nums1[i])
                i+=1
                j+=1
            elif nums1[i]<nums2[j]:
                i+=1
            elif nums1[i]>nums2[j]:
                j+=1
        return res
```

![image.png](https://pic.leetcode-cn.com/151e1068aa19364be3464d2b1a3ef2dbe140f6f92d2238b8190c071f9256113e-image.png)
