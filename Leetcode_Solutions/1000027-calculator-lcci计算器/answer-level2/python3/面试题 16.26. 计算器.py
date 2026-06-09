正则预处理分离数字和符号，然后遍历一次先计算乘除法，最后再计算加减。

```python []
class Solution:
    def calculate(self, s: str) -> int:
        s = re.sub('([*+-/])', r' \1 ', s.replace(' ', '')).split()
        (first, *nums), operates = s[:: 2], s[1:: 2]
        queue, signs = [int(first)], []
        for opr, num in zip(operates, nums):
            if opr == '*':
                queue[-1] *= int(num)
            elif opr == '/':
                queue[-1] //= int(num)
            else:
                queue.append(int(num))
                signs.append(opr == '+' and 1 or -1)
        return queue[0] + sum(i * j for i, j in zip(queue[1: ], signs))
```
```python []
class Solution:
    def calculate(self, s: str) -> int:
        return eval(s.replace('/', '//'))
```
