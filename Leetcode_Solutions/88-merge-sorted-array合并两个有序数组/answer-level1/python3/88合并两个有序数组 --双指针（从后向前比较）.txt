### 解题思路
利用双指针，从后向前比较，将比较后的较大者赋到nums1的后面，然后指针依次前移。
l:指向nums1的最后(m+n-1)，依次向前
i:指向nums1的第m-1个元素，依次向前
j:指向nums2的第n-1个元素，依次向前
若i指向0时，j还没有指向0，则把nums2的前j个元素赋值到nums1的前j个元素。

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        #双指针
        l=m+n-1
        i,j=m-1,n-1
        while i>=0 and j>=0:
            if nums1[i]<nums2[j]:#较大者赋到nums1的后面
                nums1[l]=nums2[j]
                j-=1
            else:
                nums1[l]=nums1[i]
                i-=1
            l-=1
        nums1[:j+1]=nums2[:j+1]#nums2若有剩余，直接赋到nums1的前面

```