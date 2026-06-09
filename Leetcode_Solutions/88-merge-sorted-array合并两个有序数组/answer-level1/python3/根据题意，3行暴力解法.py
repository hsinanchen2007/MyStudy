思路
直接将nums2放在nums1有效元素的后面
利用sorted排序有效的0：m+n元素，并加上未用的末尾0元素

```
class Solution:

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        """

        Do not return anything, modify nums1 in-place instead.

        """

        for i in range(n):

            nums1[m+i] = nums2[i]

        nums1[:] = sorted(nums1[0:m+n]) + (len(nums1)-m-n)*[0]

```
