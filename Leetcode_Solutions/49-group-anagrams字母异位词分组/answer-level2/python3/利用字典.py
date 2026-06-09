### 解题思路
重点是创建一个默认值类型为list的字典，之后要将字符串排序避免因顺序不同而导致键值不匹配。

### 代码

```python3
import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return ans.values()
        
```