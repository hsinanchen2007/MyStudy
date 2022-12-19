### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        while len(nums1) > 0 and len(nums2) > 0:
            if len(nums1) % 2 == 0 and len(nums2) % 2 == 0:
                a11 = nums1[len(nums1) / 2 - 1]
                a12 = nums1[len(nums1) / 2]
                a21 = nums2[len(nums2) / 2 - 1]
                a22 = nums2[len(nums2) / 2]
                if a11 <= a22 and a12 >= a21:
                    a = [a11, a12, a21, a22]
                    a.remove(min(a))
                    a.remove(max(a))
                    return (a[0]+a[1])/2.0
                    # return float((a[0] + a[1])/2)
                elif a11 > a22:
                    abadon = min(len(nums1)/2,len(nums2)/2)
                    nums1 = nums1[:len(nums1)-abadon]
                    nums2 = nums2[abadon:]
                elif a21 > a12:
                    abadon = min(len(nums1)/2,len(nums2)/2)
                    nums1 = nums1[abadon:]
                    nums2 = nums2[:len(nums2)-abadon]
            elif len(nums1) % 2 != 0 and len(nums2) % 2 != 0:
                if len(nums1)==1 or len(nums2)==1:
                    if len(nums1)==1:
                        num = nums2
                        nums2 =nums1
                        nums1 = num
                    if len(nums1)==1:
                        return (nums1[0]+nums2[0])/2.0
                    if nums2[0]>=nums1[len(nums1)/2+1]:
                        # print("jh")
                        return (nums1[len(nums1)/2]+nums1[len(nums1)/2+1])/2.0
                    elif nums2[0]<=nums1[len(nums1)/2-1]:
                        # print("jjjj")
                        return (nums1[len(nums1) / 2] + nums1[len(nums1) / 2 - 1]) / 2.0
                    else:
                        # print('jj')
                        return (nums1[len(nums1) / 2] + nums2[0]) / 2.0
                if nums1[len(nums1)/2]==nums2[len(nums2)/2] or (len(nums1)==1 and len(nums2)==1):
                    return (nums1[len(nums1)/2]+nums2[len(nums2)/2])/2.0
                elif nums1[len(nums1)/2]>=nums2[len(nums2)/2]:
                    # if nums1[len(nums1)/2-1]<=nums2[len(nums2)/2]:
                    #     return float((nums1[len(nums1)/2]+nums2[len(nums2)/2])/2.0)
                    # else:
                    abadon = min(len(nums1)/2,(len(nums2)/2))
                    nums1 = nums1[:len(nums1)-abadon]
                    nums2 = nums2[abadon:]
                else:
                    # if nums1[len(nums1)/2+1]>=nums2[len(nums2)/2]:
                    #     # print("enter 555")
                    #     return ((nums1[len(nums1)/2]+nums2[len(nums2)/2]))/2.0
                    # else:
                    abadon = min(len(nums1)/2,len(nums2)/2)
                    nums1 = nums1[abadon:]
                    nums2 = nums2[:len(nums2)-abadon]
            else:
                if len(nums1) % 2 ==1:
                    nums = nums1[:]
                    nums1 = nums2[:]
                    nums2 = nums[:]
                if nums2[len(nums2)/2]>=nums1[len(nums1)/2-1] and nums2[len(nums2)/2]<= nums1[len(nums1)/2]:
                    return nums2[len(nums2)/2]
                elif nums2[len(nums2)/2]<nums1[len(nums1)/2-1] and len(nums2)!=1:
                    abadon = min(len(nums1)/2,len(nums2)/2)
                    nums2 = nums2[abadon:]
                    nums1 = nums1[:len(nums1)-abadon]
                elif len(nums2)==1 and nums2[len(nums2)/2]<nums1[len(nums1)/2-1]:
                    return nums1[len(nums1)/2-1]
                elif len(nums2)==1 and nums2[len(nums2)/2]>nums1[len(nums1)/2]:
                    return nums1[len(nums1)/2]
                elif nums2[len(nums2)/2]>nums1[len(nums1)/2] and len(nums2)!=1:
                # print("333666")
                    abadon = min(len(nums1) / 2, len(nums2) / 2)
                    nums1 = nums1[abadon:]
                    nums2 = nums2[:len(nums2) - abadon]
                # else:
                #     print("error")




        if len(nums1) == 0 and len(nums2) % 2 == 0:
            return float((nums2[len(nums2) / 2] + nums2[len(nums2) / 2 - 1]) / 2.0)
        elif len(nums1) == 0 and len(nums2) % 2 == 1:
            return (nums2[len(nums2) / 2])
        elif len(nums2) == 0 and len(nums1) % 2 == 0:
            return float((nums1[len(nums1) / 2] + nums1[len(nums1) / 2 - 1]) / 2.0)
        elif len(nums2) == 0 and len(nums1) % 2 == 1:
            return (nums1[len(nums1) / 2])

                        

                        
                                        




```