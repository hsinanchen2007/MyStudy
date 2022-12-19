```python
    def pushDominoes(self, dominoes: str) -> str:
        pre, res = (-1, 'L'), ''  # 首部的虚拟哨兵
        for i, s in enumerate(dominoes+'R'):  # 尾部的哨兵
            if s == 'L':
                if pre[1] == 'L':
                    res += 'L'*(i-pre[0])
                else:
                    div, mod = divmod((i-pre[0]-1), 2)
                    res += 'R'*div+'.'*mod+'L'*div+'L'
                pre = (i, s)
            elif s == 'R':
                if pre[1] == 'L':
                    res += '.'*(i-pre[0]-1)+'R'
                else:
                    res += 'R'*(i-pre[0])
                pre = (i, s)
        return res[:-1]  # 去掉尾部的哨兵
```
