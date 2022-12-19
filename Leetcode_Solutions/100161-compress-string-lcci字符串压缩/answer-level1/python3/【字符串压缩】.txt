通过itertools模块中的groupby函数，把迭代器中相邻的重复元素挑出来放在一起
```python3
class Solution:
    def compressString(self, S: str) -> str:
        #if len(S) <= 2:
        #    return S
        s = ''
        # itertools.groupby(S, lambda x: x.lower()) 
        # 忽略字母大小写，并以小写格式输出
        for c, v in itertools.groupby(S):
            s += ''.join(c + str(len([*v])))
        return len(s) < len(S) and s or S
```
