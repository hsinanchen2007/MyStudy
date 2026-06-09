
## 数组未排序状态

在需要快速查找的时候优先想到了hash，但是这要求返回的次数与出现的次数一致，那么对于hash内部保存的就需要有要求，key应该为出现的元素，value应该为对应元素出现的次数
遍历第一个数组保存元素和对应的次数，遍历第二个数组时进行查询，如果出现次数>0那么为交集，且每次都要更新次数-=1
```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = {}
        res = []

        for i in nums1:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1

        for i in nums2:
            if i in dic and dic[i] > 0:
                res.append(i)
                dic[i] -= 1
        
        return res
```


## 数组为排序状态

当数组是排序的时候，就可以用双指针，类似归并查找，进行遍历找到对应相等的元素，如果相等，保存交集，如果nums1[i]<nums2[j]，那么i++，反之j++
[4,5,9]
[4,4,8,9,9]

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        nums1.sort()
        nums2.sort()
        
        res = []
        
        i = 0
        j = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                res.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        
        return res
```
