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
        # 修改nums1
        # 遍历nums2 找到nums[i]在nums1中的位置 将该位置的元素往后移动 再插入nums2[i]
        # 如果刚好是最大，则直接插入到nums1最后 nums1数组元素个数+1
        start=0
        for i in range(0,n):
            flag=0
            for j in range(start,m):
                # 找到nums2[i]插入的位置j
                if nums1[j]>=nums2[i]:
                    m+=1
                    for k in range(m-2,j-1,-1):
                        nums1[k+1]=nums1[k]
                    nums1[j]=nums2[i]
                    # 此次元素的位置的下一个作为下次遍历的开始
                    start=j
                    # 插入后break 继续nums2的下一个元素
                    flag=1
                    break
            # 插入位置为最后一个元素
            if flag==0:
                m+=1
                nums1[m-1]=nums2[i]
            
        
```
