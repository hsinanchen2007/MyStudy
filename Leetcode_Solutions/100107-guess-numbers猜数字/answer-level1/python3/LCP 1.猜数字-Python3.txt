### 解题思路
最小白的解法，看了大家的回答我深受启发，会继续努力提高效率的。

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        count = 0
        for i in range(3):
            if guess[i] == answer[i]:
                count += 1
        return count
```