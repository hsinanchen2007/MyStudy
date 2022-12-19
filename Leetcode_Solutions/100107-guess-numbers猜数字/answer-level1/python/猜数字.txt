### 解题思路
执行用时 :36 ms, 在所有 Python3 提交中击败了51.82%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.73%的用户

### 代码

```python3
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        a=0
        for i in range(len(guess)):
            if guess[i]==answer[i]:
                a+=1
        return a
```