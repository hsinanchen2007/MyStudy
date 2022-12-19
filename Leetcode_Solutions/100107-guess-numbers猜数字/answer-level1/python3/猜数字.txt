### 解题思路
直接按顺序依次遍历两个数组，看是否相等，相等则计数加1

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