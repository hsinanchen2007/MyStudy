利用set集合的无重复 + 查找O(1)复杂度的特性写的无脑答案()
```python
def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1s, res = set(), set()
        for 元素 in nums1:
            nums1s.add(元素)
        for 元素 in nums2:
            if 元素 in nums1s:
                res.add(元素)
        list = []
        for item in res:
            list.append(item)
        return list
```
