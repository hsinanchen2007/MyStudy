### 解题思路

假设n-2对应的结果为res1[], n-1对应的结果为res2[]
则n对应的结果为(遍历res1)+遍历res2

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = [[] for _ in range(n+1)]
        res[0] = [""]
        for i in range(1, n+1):
            for k in range(i):
                for l1 in res[k]:
                    for l2 in res[i-1-k]:
                        res[i].append("("+l1+")"+l2)
        return res[-1]
```