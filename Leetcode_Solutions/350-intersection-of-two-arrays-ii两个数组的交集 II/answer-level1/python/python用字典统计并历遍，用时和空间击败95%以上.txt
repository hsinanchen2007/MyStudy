### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if (len(nums1)>len(nums2)):
            nums1,nums2 = nums2, nums1
        numsdic = {}
        for i in range(len(nums1)):
            if nums1[i] not in numsdic.keys():
                numsdic[nums1[i]] = 1
            else:
                numsdic[nums1[i]] += 1
        numsnew = []
        for i in range(len(nums2)):
            if (nums2[i] in numsdic.keys())and(numsdic[nums2[i]]!=0):
                numsnew.append(nums2[i])
                numsdic[nums2[i]] -= 1   
        return numsnew
```