开始思考是从前往后，从小到大放，但是需要额外空间
如果是从后往前，先大后小，1数组放一个，会空出一个位置，空闲区域还是大于等于n，2数组放一个，2数组减少一个，空闲区域大于等于n-1，所以不需要考虑交换问题，代码如下，开始进行很多空值，数组长度等判断有点坑
```
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        if nums1 is None or m==0:
            if nums2 is None: return
            for i in range(n):
                nums1[i]=nums2[i]
            return
        if nums2 is None or n==0:return;
        while n>=1:
            if nums2[n-1]>nums1[m-1]:
                nums1[m+n-1]=nums2[n-1]
                n-=1
            else:
                nums1[m+n-1]=nums1[m-1]
                m-=1
            if m==0:
                for i in range(n):
                    nums1[i]=nums2[i]
                return
```
