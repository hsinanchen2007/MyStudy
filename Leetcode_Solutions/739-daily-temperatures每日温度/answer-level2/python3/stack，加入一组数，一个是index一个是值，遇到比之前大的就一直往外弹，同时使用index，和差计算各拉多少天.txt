### 解题思路
stack，加入一组数，一个是index一个是值，遇到比之前大的就一直往外弹，同时使用index，和差计算各拉多少天
一个for，一直走，while负责弹出，
每次for stack都加，
while，则是有条件一直弹
```
for i in range(1,len(T)):
    while stack:
        prev = stack[-1]
        if T[i]>prev[0]:
            res[prev[1]] = i - prev[1]
            stack.pop()
        else:
            break
    stack.append([T[i], i])
```

### 代码

```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:

        if T is None:
            return None
        res = [0]*len(T)
        stack = [[T[0],0]]

        for i in range(1,len(T)):
            while stack:
                prev = stack[-1]
                if T[i]>prev[0]:
                    res[prev[1]] = i - prev[1]
                    stack.pop()
                else:
                    break
            stack.append([T[i], i])

        return res     
```