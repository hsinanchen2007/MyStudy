### 解题思路

-   使用队列，不断地找出距离更小的点
-   需要注意的就是，如果距离很近，也就是周边节点需要处理

```python
from collections import deque, defaultdict


class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        mem = defaultdict(lambda: float('inf'))
        surround = [(-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2)]

        mem[(0, 0)] = 0
        d = deque()
        d.append((0, 0))

        while d:
            i, j = d.popleft()
            current_length = abs(y - j) + abs(x - i)
            if i == x and j == y:
                break
            for di, dj in surround:
                ni, nj = i + di, j + dj
                length = abs(y - nj) + abs(x - ni)
                if mem[(i, j)] + 1 < mem[(ni, nj)]:
                    if length <= current_length or current_length <= 3:
                        d.append((ni, nj))
                        mem[(ni, nj)] = mem[(i, j)] + 1
        return mem[(x, y)]

```
上面的时间复杂度较高，主要体现在两个点距离较远的情况下，有很多无效路径的搜索，因此，下面首先对这些路径进行压缩，找到距离较近的点，然后开始广度优先搜索


-   **改进版**

-   另一种方法，首先尽可能的靠近目标点，然后使用广度优先搜索
![image.png](https://pic.leetcode-cn.com/08ffe8871c85a28c5d45da467b89490220cb32afc1a9e619a71df625b78afa9b-image.png)


```python
from collections import deque, defaultdict

class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:

        steps = 0
        start = [0, 0]
        x_length = abs(x - start[0])
        y_length = abs(y - start[1])
        while x_length + y_length > 7:
            if x_length >= y_length:
                if x > start[0]:
                    start[0] += 2
                else:
                    start[0] -= 2

                if y > start[1]:
                    start[1] += 1
                else:
                    start[1] -= 1
            else:
                if x > start[0]:
                    start[0] += 1
                else:
                    start[0] -= 1

                if y > start[1]:
                    start[1] += 2
                else:
                    start[1] -= 2
            x_length = abs(x - start[0])
            y_length = abs(y - start[1])
            steps += 1

        mem = defaultdict(lambda: float('inf'))
        surround = [(-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2)]

        mem[tuple(start)] = steps
        d = deque()
        d.append(tuple(start))

        while d:
            # print(d)
            i, j = d.popleft()
            current_length = abs(y - j) + abs(x - i)
            if i == x and j == y:
                break
            for di, dj in surround:
                ni, nj = i + di, j + dj
                length = abs(y - nj) + abs(x - ni)
                if mem[(i, j)] + 1 < mem[(ni, nj)]:
                    if length <= current_length or current_length <= 3:
                        d.append((ni, nj))
                        mem[(ni, nj)] = mem[(i, j)] + 1

        return mem[(x, y)]
```


