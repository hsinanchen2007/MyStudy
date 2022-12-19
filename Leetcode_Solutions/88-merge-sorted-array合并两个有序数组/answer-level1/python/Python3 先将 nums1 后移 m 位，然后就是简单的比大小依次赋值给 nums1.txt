Python3 先将 nums1 后移 m 位，然后就是简单的比大小依次赋值给 nums1
```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        n = len(nums1)
        m = len(nums2)
        # 将 nums1 后移 m 位
        # nums1 = A 更改 nums1 这一变量名所指向的对象。
        # nums1[:] = A 对 nums1 指向的对象赋值。
        nums1[:] = nums1[-m:] + nums1[:-m]
        
        # 因为移动了所以 p1 从 m 开始
        p1 = m
        p2 = 0
        i = 0
        while p1 < n and p2 < m:
            if nums1[p1] < nums2[p2]:
                nums1[i] = nums1[p1]
                p1 += 1
            else:
                nums1[i] = nums2[p2]
                p2 += 1
            i += 1
        
        # 不需要判断 p1 < n
        # 因为我们是在 nums1 中操作，p1 剩下部分已经在num1 中了
        if p2 < m:
            nums1[i:] = nums2[p2:]
        
        return None
```
