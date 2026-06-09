### 解题思路
sorted函数会返回一个list，这个list不能直接放在dict的key
因此可以用tuple实现

### 代码

```python3
import collections


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        datas = collections.defaultdict(list)
        for s in strs:
            #print(sorted(s))
            datas[tuple(sorted(s))].append(s)
        return list(datas.values())
```