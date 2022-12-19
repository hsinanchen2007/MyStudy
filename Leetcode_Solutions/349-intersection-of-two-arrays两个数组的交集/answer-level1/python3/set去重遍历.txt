### 解题思路
set去重不算作弊吗？还可以直接用interaction函数呢！
### 代码

```python
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1 = set(nums1) # 这种去重方法不算作弊吗？
        nums2 = set(nums2)
        global res
        res = []
        if len(nums1) < len(nums2):
            self.temp(nums1, nums2)
        else:
            self.temp(nums2, nums1)
        return res

    def temp(self,nums1,nums2):
        for i in nums1:
            if i in nums2:
                res.append(i)
        return res

```