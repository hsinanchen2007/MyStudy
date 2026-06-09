### 解题思路
执行用时 :456 ms, 在所有 Python3 提交中击败了78.36%的用户
内存消耗 :15 MB, 在所有 Python3 提交中击败了6.25%的用户

### 代码

```python3
class Solution:
    def if_eaten(self, bananas, K, H):
        return sum([(num - 1) // K + 1 for num in bananas]) <= H

    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        left = 0
        right = max(piles)

        while left < right:
            speed = (left + right) // 2
            if speed == 0:
                return 1
            if self.if_eaten(piles, speed, H):
                right = speed
            else:
                left = speed + 1

        speed = (left + right) // 2
        return speed
```