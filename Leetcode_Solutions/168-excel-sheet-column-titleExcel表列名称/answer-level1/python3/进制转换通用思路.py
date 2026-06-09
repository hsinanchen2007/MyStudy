### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # def convertToTitle(self, n: int) -> str:
    #     res = ''
    #     table = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    #     while n > 0:
    #         res = table[(n - 1) % 26]+ res
    #         n = (n - 1) // 26
    #     return res

    def convertToTitle(self, n: int) -> str:
        res = []
        table = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        while n > 0:
            # 注意处理数字从1开始的问题
            res.append(table[(n - 1) % 26])
            n = (n - 1) // 26
        return ''.join(reversed(res))
```