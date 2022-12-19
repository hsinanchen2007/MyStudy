40ms,100%,纯模拟题，就是注意往z走的时候可能要折一下。
```python
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        e = {'a': [0, 0], 'b': [0, 1], 'c': [0, 2], 'd': [0, 3], 'e': [0, 4], 'f': [1, 0], 'g': [1, 1], 'h': [1, 2], 'i': [1, 3], 'j': [1, 4], 'k': [2, 0], 'l': [2, 1], 'm': [2, 2], 'n': [2, 3], 'o': [2, 4], 'p': [3, 0], 'q': [3, 1], 'r': [3, 2], 's': [3, 3], 't': [3, 4], 'u': [4, 0], 'v': [4, 1], 'w': [4, 2], 'x': [4, 3], 'y': [4, 4], 'z': [5, 0]}
        ans, a = '', 'a'
        for b in target:
            ax, ay, bx, by = e[a] + e[b]
            res = ('D' * (bx - ax) if bx > ax else 'U' * (ax - bx)) + ('R' * (by - ay) if by > ay else 'L' * (ay - by))
            if b == 'z' and ay > 0: res = res[1:] + res[0]
            ans += res + '!'
            a = b
        return ans
```
