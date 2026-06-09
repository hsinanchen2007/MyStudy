### 解题思路
构建字典，键为数，值为出现次数

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic1, dic2 = {}, {}
        for i in range(len(nums1)):
            if nums1[i] not in dic1:
                dic1[nums1[i]] = 1
            else:
                dic1[nums1[i]] += 1
        for j in range(len(nums2)):
            if nums2[j] not in dic2:
                dic2[nums2[j]] = 1
            else:
                dic2[nums2[j]] += 1
        ret = []
        for i in dic1.keys():
            if i in dic2:
                for j in range(min(dic1[i], dic2[i])):
                    ret.append(i)
        return ret
            
            

```