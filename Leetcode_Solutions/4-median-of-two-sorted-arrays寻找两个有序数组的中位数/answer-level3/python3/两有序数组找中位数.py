# 解法一
## 思路
在两有序数组合并的过程中，就可以直接算出答案。因为我们只需要中位数，所以并不用保存下合并后的数组。
时间复杂度O((m+n)/2) 空间复杂度O(1)
## code

```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n = len(nums1),len(nums2)
        msum = m+n
        if msum&1 == 0:
            r = msum//2
            l = r-1
        else:
            l = r = msum//2
        ret = 0
        i1 = 0
        i2 = 0
        for i in range(msum):
            if i1<m and i2<n:
                if nums1[i1]<=nums2[i2]:
                    tmp = nums1[i1]
                    i1+=1
                elif nums1[i1]>nums2[i2]:
                    tmp = nums2[i2]
                    i2+=1
            elif i1<m:
                tmp = nums1[i1]
                i1+=1
            elif i2<n:
                tmp = nums2[i2]
                i2+=1
            if i == l:
                ret += tmp
            if i == r:
                ret += tmp
                break
        return ret/2
```

# 解法二
## 思路
找中位数，实际上是找m+n个有序数中，找第k=(m+n)/2小的数，采用二分法，每次排除k/2个元素，所以时间复杂度O(log(k))即O(log(m+n)),空间复杂度O(1)
## code
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n = len(nums1),len(nums2)
        left = (m+n+1)//2
        right = (m+n+2)//2
        if (m+n)&1 ==0:
            return (self.findMinK(nums1,0,m-1,nums2,0,n-1,left) + self.findMinK(nums1,0,m-1,nums2,0,n-1,right))/2
        else:
            return self.findMinK(nums1,0,m-1,nums2,0,n-1,left)
    def findMinK(self,data1,start1,end1,data2,start2,end2,k):
        len1 = end1 - start1 + 1
        len2 = end2 - start2 + 1
        if len1>len2:
            return self.findMinK(data2,start2,end2,data1,start1,end1,k)
        if len1 == 0:
            return data2[start2+k-1]
        if k == 1:
            return min(data1[start1],data2[start2])
        
        i1 = min(len1,k//2)-1
        i2 = min(len2,k//2)-1
        if data1[start1+i1]>data2[start2+i2]:
            return self.findMinK(data1,start1,end1,data2,start2+i2+1,end2,k-i2-1)
        else:
            return self.findMinK(data1,start1+i1+1,end1,data2,start2,end2,k-i1-1)
```
