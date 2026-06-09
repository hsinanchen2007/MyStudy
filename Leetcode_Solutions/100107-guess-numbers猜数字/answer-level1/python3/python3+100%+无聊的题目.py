执行用时 :40 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def game(self, guess, answer):
        result = 0
        for i, j in zip(guess, answer):
            if i == j:
                result += 1
        return result
```
