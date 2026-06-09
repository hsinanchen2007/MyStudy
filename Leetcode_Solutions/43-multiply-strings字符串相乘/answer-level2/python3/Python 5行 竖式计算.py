```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        d = {}
        for i, n1 in enumerate(num1[::-1]):
            for j, n2 in enumerate(num2[::-1]): d[i + j] = d.get(i + j, 0) + int(n1) * int(n2)
        for k in [*d]: d[k + 1], d[k] = d.get(k + 1, 0) + int(d[k] * 0.1), d[k] % 10
        return re.sub('^0*', '', ''.join(map(str, d.values()))[::-1]) or '0'
```
- 本题的难点在于计算整数的时候不能超过32bits，因此使用竖式计算
- 我们遍历num1中的每个数字n1，然后带着这个数字遍历num2中的每个数字n2做乘法，所得乘积放进 d 中相应的位置然后逐位计算结果
- i + j 正好对应俩个数字相乘后所在的位置，比如 0 + 0 就应该是个位， 0 + 1 就是十位， 1 + 1 百位。
- 若完全不想使用int()可以参考：
```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        d = {}
        for i, n1 in enumerate(num1[::-1]):
            for j, n2 in enumerate(num2[::-1]):
                d[i + j] = d.get(i + j, 0) + (ord(n1) - 48) * (ord(n2) - 48)
        for k in [*d]:
            d[k + 1], d[k] = d.get(k + 1, 0) + math.floor(d[k] * 0.1), d[k] % 10
        return re.sub('^0*', '', ''.join(map(str, d.values()))[::-1]) or '0'
```
