
```python3
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        result = 0
        stack = []
        for i in ops:
            if i=="C":
                tmp = stack.pop()
                result -= tmp
            elif i == "D":
                tmp = stack[-1]
                stack.append(tmp*2)
                result += tmp*2
            elif i == "+":
                tmp = stack[-1]+stack[-2]
                stack.append(tmp)
                result += tmp
            else:
                i = int(i)
                stack.append(i)
                result += i
            print(result)
        return result
```