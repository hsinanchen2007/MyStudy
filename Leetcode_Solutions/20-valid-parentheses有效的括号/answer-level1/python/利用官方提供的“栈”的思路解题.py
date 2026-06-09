### 解题思路
用了无数个判断语句，这样写速度很慢，但是比较好理解吧
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        test_var = []
        tag = {')': '(', ']': '[', '}': '{'}
        for i in s:
            if i in tag.values():
                test_var.append(i)
            elif i in tag.keys():
                if len(test_var) == 0:
                    test_var.append(i)
                elif test_var[-1] != tag[i]:
                    test_var.append(i)
                elif test_var[-1] == tag[i]:
                    test_var.pop()
                else:
                    test_var.append(i)
            else:
                pass
        return True if len(test_var) == 0 else False
```