```
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        freq_dict = {}
        for num in arr:
            freq_dict[num] = freq_dict.get(num, 0) + 1
        return len(set(freq_dict.values())) == len(freq_dict.values())
```

抖个机灵，其实写代码没必要追求短，不墨迹就行了