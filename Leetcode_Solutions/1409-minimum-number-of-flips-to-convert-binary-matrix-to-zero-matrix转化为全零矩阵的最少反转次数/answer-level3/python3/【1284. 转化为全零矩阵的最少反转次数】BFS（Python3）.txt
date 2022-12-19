# I'm lucifer

## 思路

常规BFS。 

- 初始状态是题目给的mat
- 目标状态是全0mat


## 代码

```python
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        # 放到 flip 函数外面可以减少计算
        mapper = {'0': '1', '1': '0'}

        def flip(state, i):
            state[i] = mapper[state[i]]
            if i % n != 0:
                state[i - 1] = mapper[state[i - 1]]
            if i % n < n - 1:
                state[i + 1] = mapper[state[i + 1]]
            if i >= n:
                state[i - n] = mapper[state[i - n]]
            if i < (m - 1) * n:
                state[i + n] = mapper[state[i + n]]

        m = len(mat)
        n = len(mat[0])
        target = '0' * (m * n)
        cur = ''.join(str(cell) for row in mat for cell in row)

        queue = [cur]
        visited = set()
        steps = 0

        while len(queue) > 0:
            for _ in range(len(queue)):
                cur = queue.pop(0)
                if cur == target:
                    return steps
                if cur in visited:
                    continue

                visited.add(cur)
                for i in range(len(cur)):
                    s = list(cur)
                    flip(s, i)
                    queue.append(''.join(s))
            steps += 1

        return -1
```

**复杂度分析**

- 时间复杂度：由于所有的状态共有 2 ^ (M \* N) 个，因此总的时间复杂度为$O(2^(M * N))$，其中 M 为矩阵的行数，N 为矩阵的列数。
- 空间复杂度：由于我们需要存储所有的遍历过的状态，因此总的空间复杂度为$O(2^(M * N))$，其中 M 为矩阵的行数，N 为矩阵的列数。

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
