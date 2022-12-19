### 解题思路
这题算是简单中的简单吧...
不需要解题思路...

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        if n < 1: return []
        A = []
        for i in range(1, n + 1):
            ans = ""
            if i % 3 == 0: ans += "Fizz"
            if i % 5 == 0: ans += "Buzz"
            if len(ans) <= 0:
                ans = str(i)
            A.append(ans)
        return A
```