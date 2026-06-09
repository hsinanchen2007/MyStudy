### 解题思路
不明白为什么题目分类是排序 :3

思路：将两个队列按照元素出现的次数进行统计得到字典，两个字典中key相同的，返回value更小的那一个，是次数重复出现的交集。

### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) == 0 or (len(nums2) == 0):
            return []

        dictNums1 = {}  # 统计nums1
        for num in nums1:
            value = dictNums1.get(num)
            if value is None:
                dictNums1[num] = 1
            else:
                dictNums1[num] += 1
        
        dictNums2 = {}  # 统计nums1
        for num in nums2:
            value = dictNums2.get(num)
            if value is None:
                dictNums2[num] = 1
            else:
                dictNums2[num] += 1
            
        intersection = []
        keyList1 = list(dictNums1.keys())
        keyList2 = dictNums2.keys()
 
        for key in keyList1:  # keyList1和keyList2可以互换：如果不在keyList1/keyList2中，那肯定不在交集中
            if key in keyList2:
                intersection.extend([key] * min(dictNums1.get(key), dictNums2.get(key)))
        return intersection

```