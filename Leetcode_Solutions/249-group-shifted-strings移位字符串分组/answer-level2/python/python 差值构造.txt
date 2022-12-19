Python里面的dict键值只能是可哈希对象，像list、set这些，都是不能当键用的，所以这里用了tuple做键值
构造方法比较简单，就是遍历一遍字符串(假定长度为k)，将前后的字母差值记录下来，形成一个长度为k-1的tuple，然后当键


```python
from collections import defaultdict


class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        record = defaultdict(list)
        for s in strings:
            record[self._hash(s)].append(s)
        
        return list(record.values())
    
    def _hash(self, s):
        return tuple((ord(s[i]) - ord(s[i - 1])) % 26 for i in range(1, len(s)))
```