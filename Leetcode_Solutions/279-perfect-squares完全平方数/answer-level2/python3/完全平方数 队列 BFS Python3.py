### 解题思路
执行用时 :812 ms, 在所有 Python3 提交中击败了65.13%的用户
内存消耗 :18.8 MB, 在所有 Python3 提交中击败了5.20%的用户

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        l = int(n**0.5)
        squ_nums = [i**2 for i in range(1, l+1)]
        seen = set()
        queue = deque()
        queue.append((n, 1))
        seen.add((n, 1))

        while queue:
            value, depth = queue.popleft()
            for num in squ_nums:
                res = value - num
                if res == 0:
                    return depth
                if res > 0:
                    if (res, depth+1) not in seen:
                        queue.append((res, depth+1))
                seen.add((res, depth+1))
```