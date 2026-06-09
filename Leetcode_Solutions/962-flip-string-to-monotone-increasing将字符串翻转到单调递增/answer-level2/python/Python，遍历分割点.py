```python
    def minFlipsMonoIncr(self, S: str) -> int:
        # 基本思路是遍历所有分隔点找最小值
        l, r, _sum = [0], [0], 0
        for i in S:
            if i == '1':
                _sum += 1
            l.append(_sum)  # 将左边全翻转为0需要的翻转次数
        _sum = 0
        for i in reversed(S):
            if i == '0':
                _sum += 1
            r.append(_sum)  # 将右边全翻转为1需要的翻转次数
        r.reverse()
        return min(l[i]+r[i] for i in range(len(l)))
```
