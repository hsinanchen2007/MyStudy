### 解题思路
填色问题，首先保存路径，然后设置四种颜色，晒出路径中有的颜色，选择color[0]填色

### 代码

```python3
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        recoder = {i : [] for i in range(1, N + 1)}
        for i in paths:
            recoder[i[0]].append(i[1])
            recoder[i[1]].append(i[0])
        ret = [0, 1]
        for i in range(2, N + 1):
            color = [1, 2, 3, 4]
            sub = recoder[i]
            for j in sub:
                if j < len(ret):
                    if ret[j] in color:
                        color.remove(ret[j])
            ret.append(color[0])
        return ret[1:]
```