### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        j = 0
        for i in range(3):
            if guess[i]==answer[i]:
                j += 1
        return j
```