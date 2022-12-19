### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        d = 1
        max_d = 1
        l = [0 for i in range(len(seq))]
        for i in range(1,len(seq)):
            if seq[i] == ')':
                d -= 1
            else:
                d+=1
                max_d = max(max_d,d)
        sign = max_d//2
        n0 = 0
        n1 = 0
        for i in range(len(seq)):
            if seq[i] == '(' and n0 < sign:
                l[i] = 0
                n0 += 1
            elif seq[i] == '(' and n0 >= sign:
                l[i] = 1
            elif seq[i] == ')' and n0 != 0:
                l[i] = 0
                n0 -= 1
            elif seq[i] == ')' and n0 == 0:
                l[i] = 1
        return l
```
1. 遍历字符串求出最大深度max_depth
2. 数连续的'('归为A，一旦达到max_depth//2,后面的再有连续的'('归为B
3. 出现')'，若A组'('数量不为0，则A组'('数量减1，否则归为B组。