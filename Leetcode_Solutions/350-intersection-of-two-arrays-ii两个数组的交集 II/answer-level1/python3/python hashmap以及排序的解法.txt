利用python解答

```
# hashmap
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import defaultdict
        tmp = defaultdict(int)
        res = []
        for i in nums1:
            tmp[i]+=1
        for i in nums2:
            if i in tmp:
                res.append(i)
                tmp[i]-=1
            if tmp[i]==0:
                tmp.pop(i)
                if len(tmp) == 0:
                    break
        return res

# 排序
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort() # nlogn
        nums2.sort()
        lefti = 0
        righti = 0
        res = []
        while lefti < len(nums1) and righti < len(nums2):
            if nums1[lefti] == nums2[righti]:
                res.append(nums1[lefti])
                lefti+=1
                righti+=1
            elif nums1[lefti] < nums2[righti]:
                lefti+=1
            elif nums1[lefti] > nums2[righti]:
                righti+=1
        return res

```
