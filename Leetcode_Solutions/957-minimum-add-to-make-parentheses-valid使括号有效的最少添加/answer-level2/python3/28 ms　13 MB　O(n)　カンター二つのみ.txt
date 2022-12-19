### 解题思路
カンター１：(と)の対を確認する。丁度対の場合は0
カンター２：対にならない)の数を足す
最後にカンター1とカンター2を足した結果を戻す

### 代码

```python3
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        balance = 0
        over = 0
        for c in S:
            if c == "(":
                balance += 1
            elif c == ")":
                if balance == 0:
                    over += 1
                else:
                    balance -= 1
        return balance + over

```