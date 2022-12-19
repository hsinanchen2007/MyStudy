
python 的语法糖和内置方法真的漂亮
```
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        # 极简算法
        A = sum(s==g for s,g in zip(secret,guess))
        B = sum((collections.Counter(secret)&collections.Counter(guess)).values())-A
        return "{A}A{B}B".format(A=A,B=B)
```
