取巧，用了内置的hash函数，这个东西在一次运行过程中，对字符串hash的值是保持不变的，而且python里面长度为1的字符串是驻留内存的，里面有坑，建议看看https://github.com/satwikkansal/wtfpython
```python
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        record = defaultdict(list)
        for s in strs:
            record[self._gen_key(s)].append(s)
        
        return list(record.values())

    def _gen_key(self, string):
        return sum(hash(i) for i in string)
```

缺点是，有非常小的概率产生碰撞，但是忽略不计了。
时间复杂度O(n * k)，k是单词的最大长度，如果单词长度是常数级别的，那算法也就到了O(n)了