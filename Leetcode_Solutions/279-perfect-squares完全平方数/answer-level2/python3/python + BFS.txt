```python
class Solution:
    def numSquares(self, n: int) -> int:
        # bfs
        queue =  collections.deque()
        squares = []
        visited = set()
        num = 1
        while True:
            sq = num * num
            if sq > n: break
            squares.append(sq)
            visited.add(sq)
            queue.append((sq, 1))
            num += 1

        if n in visited: return 1 # special case
        while True:
            length = len(queue)
            for _ in range(length):
                curVal, curSteps = queue.popleft()
                for s in squares:
                    if curVal + s == n: return curSteps + 1
                    elif curVal + s < n and curVal + s not in visited:
                        queue.append((curVal + s, curSteps + 1))
                        visited.add(curVal + s)
```