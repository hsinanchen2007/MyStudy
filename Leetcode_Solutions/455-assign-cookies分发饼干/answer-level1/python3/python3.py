### 解题思路
首先将孩子的胃口值和饼干的大小从小到大排列，这个很关键！
排序好后开始遍历，从第一个孩子 第一块饼干开始，如果饼干可以满足孩子的胃口，那么就第二个孩子，第二块饼干，满足孩子的数量+1，如果这块饼干不能满足这个孩子，那么就看下一块饼干，当前孩子是胃口值最小的孩子，如果所有的饼干都不能满足，也就不用看后面的孩子了，能满足的数量就为0，排序的作用在这里。
遍历要控制变量，孩子个数和饼干数量都要控制。

```python3
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int: 
        s.sort()
        g.sort()
        ls,lg = len(s),len(g)
        i,j,res = 0,0,0
        while i<lg and j<ls:   
                if g[i] <= s[j]:    
                    i += 1
                    j += 1
                    res += 1          
                else:             
                    j += 1
        return res
```