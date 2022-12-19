### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        res =[]
        for i in strs:
            dic.setdefault(str(sorted(i)),[]).append(i)
        for value in dic.values():
            res.append(value)
        return res
            


```