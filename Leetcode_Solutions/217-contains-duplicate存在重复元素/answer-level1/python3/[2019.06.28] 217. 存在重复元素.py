(1) Hash Table
```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        _dict = {}
        for i, element in enumerate(nums):
          if _dict.get(element) is not None:
            return True
          _dict[element] = i

        return False
```

(2) Map
(3) 数组排序, 看相邻数字是否相等