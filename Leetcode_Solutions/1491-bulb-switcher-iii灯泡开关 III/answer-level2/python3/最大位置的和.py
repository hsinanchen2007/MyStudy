看上去很复杂，但是想想又很简单的题目：最大亮灯位置左边必须都亮。
```python3
    def numTimesAllBlue(self, light: List[int]) -> int:
        s = m = res = 0
        for n in light:
            s += n
            m = max(m, n)
            if s == (1 + m) * m // 2: res += 1
        return res
```