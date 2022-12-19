### 解题思路
先建立一個字典 
再對文字排序作為字典的key 
再依序放入各個Key中

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)
        for i in strs:
            s_c = i
            s = sorted(list(s_c))
            ss = ""
            for j in s:
                ss += j
            res[ss].append(i)

        ans = []
        for key in res:
            ans.append(res[key])
        return ans    


```