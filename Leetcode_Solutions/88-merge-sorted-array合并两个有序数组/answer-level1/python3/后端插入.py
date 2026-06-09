执行用时 :36 ms, 在所有Python3提交中击败了99.97% 的用户。
内存消耗 :12.9 MB, 在所有Python3提交中击败了98.21%的用户。

从尾部元素进行比较，依次把较大的元素放入列表尾部，空间复杂度O(1)。

```
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        a = m -1
        b = n - 1  #数组nums1和nums2尾部元素的下标（0不考虑）
        res = m+n-1  #nums1数组尾部下标，记录插入的位置
        while a >= 0 and b >= 0:
            if nums1[a] > nums2[b]:
                nums1[res] = nums1[a]
                a -= 1
            else:
                nums1[res] = nums2[b]
                b -= 1
            res -= 1  #每次插入需要将下次插入的位置下标更新
        nums1[:b+1] = nums2[:b+1]  #将nums2中未插入的元素（一定比nums1中的元素小）直接赋值到nums1的对应位置
```