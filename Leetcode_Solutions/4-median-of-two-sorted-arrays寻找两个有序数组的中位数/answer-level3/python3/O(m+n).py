
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        def calmedian(nums):
            if not nums:
                return None
            length = len(nums)
            if length%2 == 1:
                return(nums[length//2])
            return (nums[length//2] + nums[length//2 -1])/2
        
        def combinetwosortedlist(nums1, nums2):
            if not nums1: return nums2
            if not nums2: return nums1
            #四个指针
            i, j = 0, len(nums1)-1
            k, l = 0, len(nums2)-1
            #占位数组
            total_len = len(nums1) + len(nums2)
            total_list = [None]*total_len
            lastoop = False
            while i<=j or k<=l:
                #两个指针都相遇,标识这是最后一次循环,赋值完成后break
                if i==j and k==l:
                    lastoop = True
                #小端递增
                if nums1[i]<nums2[k]: 
                    total_list[i+k] = nums1[i]
                    i = min(i+1, j)
                else:
                    total_list[i+k] = nums2[k]
                    k = min(k + 1, l)
                #大端递减
                if nums1[j]<nums2[l]:
                    total_list[j+l+1] = nums2[l]
                    l = max(l - 1, k)
                else:
                    total_list[j+l+1] = nums1[j]
                    j = max(j - 1, i)
                if lastoop: break
            return total_list

        if not nums1:
            return calmedian(nums2)
        if not nums2:
            return calmedian(nums1)
        return calmedian(combinetwosortedlist(nums1, nums2))

```
