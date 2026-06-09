### 解题思路
利用Python的集合内元素顺序由迭代顺序决定，直接使用collection构造dictionary型的统计集合，只要存在计数为1的元素即可

### 代码

```python3
import collections
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i,j in collections.Counter(s).items():
            if j==1:return s.index(i)
        return -1
```