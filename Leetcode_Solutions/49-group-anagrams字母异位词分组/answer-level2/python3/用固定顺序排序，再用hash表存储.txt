### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        p={}
        for i in strs:
            s = "".join((lambda x: (x.sort(), x)[1])(list(i)))
            if s not in p:
                p[s]=[]
                p[s].append(i)
            else:
                p[s].append(i)
        k=[]
        for i in p:
            k.append(p[i])
        return k
```