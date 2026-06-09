```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [*(collections.Counter(nums1) & collections.Counter(nums2)).elements()]
```
- 对于两个 Counter 对象，与操作意味着取两者都有的key, value取小的那一个
```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        r = []
        i = j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                r.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return r
```
- 进阶解法 ↑
- 使用双指针将两个列表中共同的元素抠下来，因为已经排序，所以遇到不同元素时数值小的那个列表的指针向前移动