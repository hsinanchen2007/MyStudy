### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not amount or not coins:return 0
        # BFS
        visited = set()
        visited.add(amount)
        queue = []
        queue.append(amount)
        height = 0
        while queue:
            size = len(queue)
            height += 1
            for i in range(size):
                current = queue.pop(0)
                for i in range(len(coins)):
                    if current - coins[i] == 0:
                        return height
                    elif current - coins[i] > 0 and current - coins[i] not in visited:
                        queue.append(current - coins[i])
                        visited.add(current - coins[i])
        return -1
```