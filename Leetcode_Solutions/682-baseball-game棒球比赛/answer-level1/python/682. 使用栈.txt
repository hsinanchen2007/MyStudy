### 解题思路
读题一小时，变成编程一分钟。
题目中只给出四种情况：
1. 数字，就是本轮得分
2. +，就是本轮得分是前两轮相加
3. D，就是本轮得分是前一轮的两倍
4. C，删掉最后一轮得分
除了C是操作以外，其他均是当前该轮的得分，也就是可以把+、D都当成数值的。

那么问题变成：
遇到数值，就放入到新的stack中，如果遇到C，就pop最后一个数值。

### 代码

```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        res = []
        for op in ops:
            if op == 'C':
                res.pop()
            elif op == '+':
                res.append(res[-1] + res[-2])
            elif op == 'D':
                res.append(res[-1]*2)
            else:
                res.append(int(op))
        
        return sum(res)
```