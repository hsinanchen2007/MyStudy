### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numEquivDominoPairs(self, dominoes):
        """
        :type dominoes: List[List[int]]
        :rtype: int
        """
        for i in range(len(dominoes)):
            dominoes[i]="".join(list(map(str,sorted(dominoes[i]))))
        res=0
        sset={}
        for x in dominoes:
            res+=sset.get(x,0)
            sset[x]=sset.get(x,0)+1
        return res
```