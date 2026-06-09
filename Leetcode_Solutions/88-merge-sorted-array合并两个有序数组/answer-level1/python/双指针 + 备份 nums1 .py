```
class Solution(object):
    def merge(self, nums1, m, nums2, n):
       
        nums1_bak = nums1[0:m] #备份存储nums1 前几位
        p1 = p2 = index = 0
        while ( p1 < m and p2 < n):
            if nums1_bak[p1] <= nums2[p2]:               
                nums1[index] = nums1_bak[p1]
                p1 += 1               
            else:
                nums1[index] = nums2[p2]
                p2 += 1
            index += 1 
          
        #处理剩余尾巴
        if p1 == m:
            nums1[p1+p2:] = nums2[p2:]
        else:
            nums1[p1+p2:] = nums1_bak[p1:]
       
```
这里，如果使用nums1.append 的话，需要把原来nums1 清空，那么需要使用del nums1[:] 或 nums1[:] = [] 的技巧