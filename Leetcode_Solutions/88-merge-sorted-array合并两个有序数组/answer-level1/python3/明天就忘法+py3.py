### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=m-1
        j=n-1
        k=m+n-1
        # 两个数组从后向前比较 大的放到最后一个 k位置
        # 必须要两个同时大于0 ，当j走完i没走完直接返回nums1
        # 当j没走完 i走完 剩下直接放到i前面
        while i>=0 and j>=0:
            if nums1[i]>=nums2[j]:
                nums1[k]=nums1[i]
                k-=1
                i-=1
            else:
                nums1[k]=nums2[j]
                k-=1
                j-=1
        # 当数组nums2还有剩余的情况
        while j>=0:
            nums1[k]=nums2[j]
            k-=1
            j-=1
        return nums1


```