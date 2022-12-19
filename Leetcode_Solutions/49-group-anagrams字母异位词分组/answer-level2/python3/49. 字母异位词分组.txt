### 解题思路
这道题就是考哈希表的使用，尤其是collections.defaultdict可以提前设置值的类型，确实好用，键必须是不变的类型，如字符串、数字以及元组，这是需要注意的两点。

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)
        for val in strs:
            res[tuple(sorted(val))].append(val)
        return list(res.values())
```