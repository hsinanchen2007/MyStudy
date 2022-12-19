按照堆栈的意思做很好做，但是要注意几个点：
1.负数的检索
2.除数的结果（结果应向0取整）

```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num = []
        i = 0
        while i < len(tokens):
            try:
                if isinstance(int(tokens[i]),int):
                    num.append(int(tokens[i]))
                    i += 1
                    continue
            except:
                b = num.pop()
                a = num.pop()
                if tokens[i] == "+":
                    num.append(a+b)
                elif tokens[i] == '-':
                    num.append(a-b)
                elif tokens[i] == '*':
                    num.append(a*b)
                elif tokens[i] == '/':
                    if a < 0 and b < 0:
                        num.append(a//b)
                        i += 1
                        continue
                    elif a < 0 or b < 0:
                        num.append(math.ceil(a/b))
                    else:
                        num.append(a//b)
                i += 1
                
        return num[0]
```