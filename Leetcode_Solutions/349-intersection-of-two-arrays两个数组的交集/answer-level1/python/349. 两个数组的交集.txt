- 40 ms, 在所有 Python 提交中击败了85.74%的用户
- 除了set内置的方法外，还可以用字典的方式;
```
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        S1, S2 = set(nums1), set(nums2)
        L = []
        for i in S1:
            if i in S2:
                L.append(i)
        return L
```


- S1 & S2 交集
```
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]

        nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        return [9,4]
        """
        S1, S2 = set(nums1), set(nums2)
        return list(S1 & S2)
```
