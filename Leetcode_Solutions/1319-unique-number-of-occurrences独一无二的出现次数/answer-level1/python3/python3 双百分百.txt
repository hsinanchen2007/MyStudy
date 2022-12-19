用字典表示键值对每个数的出现次数，判断字典值有没有重复就好

```python3
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        s = {}
        for i in arr:
            if i not in s.keys():
                s[i] = 1
            else:
                s[i] += 1
        return len(s.values()) == len(set(s.values()))
```