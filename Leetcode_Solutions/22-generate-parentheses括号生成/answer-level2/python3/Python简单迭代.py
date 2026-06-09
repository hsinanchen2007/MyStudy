### 解题思路
观察可以看到，第n对括号的结果是n-1对括号在每个位置插入一对括号得到

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        res.append("()")
        if n == 1:
            return res
        for i in range(2, n+1):
            temp = set()
            for item in res:
                for j in range(1, len(item)):
                    temp.add(item[:j] + '()' + item[j:])
                temp.add(item + "()")
            res = list(temp)[:]
        return res
```