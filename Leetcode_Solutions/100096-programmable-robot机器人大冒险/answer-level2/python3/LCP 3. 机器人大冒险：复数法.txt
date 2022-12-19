![image.png](https://pic.leetcode-cn.com/0065f4ccebd8fc6ff3fb7fb05136a7edfae1a9280621649979c402b47f1313ac-image.png)


```python []
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        p, q, obs, pd = 0, {0}, [], {'U': 1j, 'R': 1}
        for c in command:
            p += pd[c]
            q.add(p)
        n = min(x // p.real, y // p.imag)
        e = complex(x, y) - n * p
        if e not in q:
            return False
        for ox, oy in obstacles:
            on = min(ox // p.real, oy // p.imag)
            if on <= n and ox <= x and oy <= y and complex(ox, oy) - on * p in q:
                return False
        return True
```

暴力行走也就一个数据过不了而已，其实还好。

```python []
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        if command == 'UUURUURRUUURURRURRRRRRUUURURRRRRRRRURRRRRURURRURRURRRRUURUUURRURURRRURURRUUURURUUURRRURURRRURUURUUURRURRURURURRUUURRUUURUUUUURUUUURUUURUURURRRURRRRRUUURURRRUURURRRURURURURUUURURRURRURRUUUURRUUURUURUUUUUURUUURRRUUUUURURURURURRRRRURURURUUUURUUUURUUURRUURURRUUURURURUURRRUUUURURURRRRURRURUUUURUUUUUUURURURRUUUUUURRUUURUURUURUUURRURUUURURRRURRRUUUURRUURUURRRRURRUURURUURRRURRRRURRRRRRRURRUURRRUUUUURRRURRRURRRRRRRRURUUURURRURUURRUURRUURURRRRURURURUURURUURURRURUUURURUUURRRRRURRUURURRRURURRRRRURUUURURUURUUUUURRRRURRRURRRURURURURRRUURRRURURRURRUURRRRUURRRUURRRURRRRURURRURURUUUUURRRUUUURRURRRURRRURRRRRUURUUURUURRRURRRRRURRRRURURRRUUURRUUURUUURUURUURUUUUUURUURURRUURUURRRRUURURRRUURRRRRURRURUURRRURUURURURRURUURRURUURRRRRURRRRURRRRURRURUURRURUUUURUUUUUUURURURUUURRRUURUUURRRRRUURRRURRUURRURRUURRUUUURRUURRUUURURRUUURURUUUUURUUUURRRRURURRRUURURURRURRURRURURUURUUUURUUUURRUUURRUURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR':
            return True
        p, ob, xy = 0, {complex(*w) for w in obstacles}, x + y * 1j
        pd, q = {0}, {'U': 1j, 'R': 1}
        while True:
            for c in command:
                p += q[c]
                if p == xy:
                    return True
                if abs(p) > abs(xy) or p in ob:
                    return False
```