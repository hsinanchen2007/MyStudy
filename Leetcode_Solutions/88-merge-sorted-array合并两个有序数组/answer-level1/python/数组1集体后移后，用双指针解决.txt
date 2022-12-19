先把数组1所有数字移到最后面，前面腾出了数组2长度的空间，然后用2个指针分别指针2个数组串的开头，一个指针指着带填充的下标，反复比较即可。
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
        if not nums2:
            return nums1
        for i in range(m-1,-1,-1):  #后移数组
            nums1[i+n] = nums1[i]
        i = 0   #待填充指针
        c1 = len(nums1)-m #1指针
        c2 = 0  #2指针
        while 1:
            if c2 >= n: #数组2数字用完了就不用比较了，剩下的都是1数组的数字了
                break
            if c1 >= len (nums1) or nums1[c1] > nums2[c2]:
                nums1[i] = nums2[c2]
                c2 += 1
            else:
                nums1[i] = nums1[c1]
                c1 += 1
            
            i += 1
            if i >= len(nums1):
                break
        
```
