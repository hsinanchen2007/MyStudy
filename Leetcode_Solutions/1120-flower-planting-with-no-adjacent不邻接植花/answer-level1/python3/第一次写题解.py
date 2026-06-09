### 解题思路
当N小于等于4时，直接给每个花圃分配一种花
当N大于4时
1. 构造每个花圃的邻接花圃；
2. 对于1到4号的花圃，直接种植相对应编号的花；
3. 花圃号大于4时，初始时可以选择四种，根据该花圃的邻接花圃，去除掉不能种植的花

### 代码

```python3
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        if N<=4:
            return list(range(1,N+1))
        
        link = [[] for i in range(N+1)]
        for i in paths:
            link[i[0]].append(i[1])
            link[i[1]].append(i[0])
        res = [0]*(N+1)

        for index, i in enumerate(link):
            
            if index<=4:
                res[index] = index
            else:
                able = [1,2,3,4]
                for j in i:
                    if res[j]!=0 and res[j] in able:
                        able.remove(res[j])
                res[index] = able[0]
        return res[1:]
```