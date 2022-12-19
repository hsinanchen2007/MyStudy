### 解题思路
用hash table来储存有订位的排。如果此排有订位，那么首先查看2-5，6-9，其次查看4-7。最后把没有订位的排算上即可。
### 代码

```python
class Solution:
    def maxNumberOfFamilies(self, n: int, rs: List[List[int]]) -> int:
        res, dic = 0, {}
        for r, c in rs:
            if r not in dic:
                dic[r] =set([c])
            else:
                dic[r].add(c)
                
        for i in dic:            
            cnt = all([j not in dic[i] for j in range(2, 6)]) + all([j not in dic[i] for j in range(6, 10)])
            if cnt == 0:
                cnt += all([j not in dic[i] for j in range(4, 8)])            
            res +=cnt
        return res + 2*(n - len(dic.keys()))
```