### 解题思路
时间复杂度：O（n2）
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        """
        令邻接表解决
        """
        if not paths:
            return [1] * N
        G = [[] for i in range(N)]
        l1 = len(paths)
        for i in range(l1):
            G[paths[i][0] - 1].append(paths[i][1] - 1)
            G[paths[i][1] - 1].append(paths[i][0] - 1)

        color_list = [1, 2, 3,4]

        answer = [0 for i in range(N)]
        for i in range(N):
            temp_color_list = color_list.copy()
            for j in G[i]:
                if answer[j] in temp_color_list:
                    temp_color_list.remove(answer[j])
            if temp_color_list:
                answer[i] = temp_color_list[0]
        return answer
```