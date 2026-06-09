### 解题思路
开头来回pop

### 代码

```python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        pos=len(nums1)+len(nums2)
        pos2=pos
        pos=(pos+1)/2
        
        while nums1 and nums2 and pos>1:
            if nums1[0]<=nums2[0]:
                nums1.pop(0)
            else:
                nums2.pop(0)
            pos-=1
        while pos>1:
            if nums1:
                nums1.pop(0)
                pos-=1
            if nums2:
                nums2.pop(0)
                pos-=1
            
        print nums1
        print nums2
        result=[]
        result.append(nums1.pop(0)) if nums1 else None
        result.append(nums1.pop(0)) if nums1 else None
        result.append(nums2.pop(0)) if nums2 else None
        result.append(nums2.pop(0)) if nums2 else None
        print result
        print pos2
        if  pos2%2:
            print '返回单个数'
            return min(result)
        return sum(sorted(result)[:2])/2.0


            

```