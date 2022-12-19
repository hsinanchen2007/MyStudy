不需要每次括号结束就把括号里的数字修改，只需要在左括号的位置记录增加倍数之后再有括号位置记录需要还原的倍数即可。
例如 K4(ON(SO3)2)2 生成的栈是
[(K, 4), 2, (O, 1), (N, 1), 2, (S, 1), (O, 3), -2, -2]
在最后统计时，初始倍数为 1，遇到正数增加相应倍数，负数缩小相应倍数

```
class Solution(object):
    def countOfAtoms(self, formula):

        st, p = [], []
        for m in re.finditer(r'([A-Z][a-z]*)(\d*)|\(|\)(\d+)', formula):
            if m.group(1):
                st.append((m.group(1), int(m.group(2)) if m.group(2) else 1))
            elif m.group() == '(':
                p.append(len(st))
                st.append(0)
            else:
                n = int(m.group(3))
                st[p.pop()] = n
                st.append(-n)
        d, n = {}, 1
        for x in st:
            if isinstance(x, int):
                n = n * x if x > 0 else n // -x
            else:
                d[x[0]] = d.get(x[0], 0) + x[1] * n
        
        return ''.join(k + str(n) if n > 1 else k for k, n in sorted(d.items()))
```

