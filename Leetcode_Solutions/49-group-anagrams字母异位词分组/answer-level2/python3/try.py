### 解题思路
try

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic={}
        for i in strs:
            a =tuple(sorted(i))
            if a not in dic:
                dic[a] = [i]
            else:
                dic[a].append(i)
        m=[i for i in dic.values()]
        return m
        
```