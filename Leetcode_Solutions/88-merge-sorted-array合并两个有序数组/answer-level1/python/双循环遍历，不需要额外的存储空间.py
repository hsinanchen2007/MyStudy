### 解题思路
在nums1有数的部分没结束时，往里插入nums2的元素，计数同时将结尾的0删掉一个，计数是为了以后判段nums1有数的部分是否结束了，结束了以后直接将nums2中的元素值赋值到nums1中，p是记录nums遍历到哪的索引。

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p=0
        q=m-1
        for i in range(0,n):
            for j in range(p,m+n):
                if nums1[j]>nums2[i]:
                    nums1.insert(j,nums2[i])
                    nums1.pop()
                    q=q+1
                    break
                if j>q:
                    nums1[j]=nums2[i]
                    q=q+1
                    break
            p=j
        
```