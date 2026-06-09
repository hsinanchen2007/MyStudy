主要目如何将两个不同长短的有序数组进行拆分，使得左侧个数等于右侧个数并且左侧的最大值小于右侧的最小值。
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m,n=len(nums1),len(nums2)
        if m>n:
            m,n,nums1,nums2=n,m,nums2,nums1
        if n==0:
            return ValueError
        #m<n,n如果也等于零那么两个数组都为空
        imin,imax,half_len=0,m,(m+n+1)//2
        #(m+n)%2==1左侧比右侧多一个数，中位数是左边的最大数
        #(m+n)%2==0左侧和右侧数一样多，中位数就是左边最大数减右边最小数
        while imin<=imax:
            i=(imin+imax)//2
            j=half_len-i
            if i<m and nums2[j-1]>nums1[i]:
                imin=i+1
            #nums2[j-1]>num1[i]说明左侧有值大于右侧
            #我们的前提是左侧的最大值要小于右侧最小值，所以应该增加i的值
            elif i>0 and nums1[i-1]>nums2[j]:
                imax=i-1
            #这说明左侧有值大于右侧，所以我们要增加j的值，即相当于减少i的值
            else:
                if i==0:
                    max_left = nums2[j-1]
                #i=0表示数组nums1在左侧没有任何数，所以左侧最大值就是nums2[j-1]
                elif j==0:
                    max_left = nums1[i-1]
                #同理j=0表示数组nums2在左侧没有任何数，所以左侧最大值就是num1[i-1]
                else:
                    max_left = max(nums1[i-1],nums2[j-1])
                #i和j都不等于零时，则选出它们当中的最大值
                if (m+n)%2==1:
                    return max_left
                #(m+n)%2==1左侧比右侧多一个数，中位数就是左边的最大数
                if i==m:
                    min_right = nums2[j]
                #i==m时表示nums1在右侧没有任何数，所以右侧最小值就是nums2[j]
                elif j==n:
                    min_right = nums1[i]
                #j==n时表示nums2在右侧没有任何数，所以右侧最小值就是nums1[i]
                else:
                    min_right = min(nums1[i],nums2[j])
                
                return (max_left+min_right)/2.0
```
