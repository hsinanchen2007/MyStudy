
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        anum = len(nums1) + len(nums2)
        odd = anum % 2 == 1
        mn = (anum +1) // 2
        if len(nums2) > len(nums1):
            nums1, nums2 = nums2, nums1
        #print(len(nums1), len(nums2))    
        r1 = mn-1
        l1 = mn-len(nums2) - 1
        #print('l1', l1, 'r1', r1)
        while l1 <= r1:
            m1 = l1 + (r1-l1)//2
            m2 = mn - m1 -1 - 1
            #print('l1', l1, 'r1', r1, 'm1', m1, 'm2', m2)
            if m1+1<len(nums1) and m2>=0 and nums1[m1+1] < nums2[m2]:
                l1 = m1 + 1
            elif (m2+1<len(nums2)) and m1>=0 and (nums1[m1] > nums2[m2+1]):
                r1 = m1 - 1
            else:
                break
        #print('l1', l1, 'r1', r1, 'm1', m1, 'm2', m2)
        ll = []
        rr = []
        if m1>=0:
            ll.append(nums1[m1])
        if m2>=0:
            ll.append(nums2[m2])
        if m1+1 < len(nums1):
            rr.append(nums1[m1+1])
        if m2+1 < len(nums2):
            rr.append(nums2[m2+1])
        if odd:
            return max(ll)
        else:
            return (max(ll) + min(rr))/2

```

