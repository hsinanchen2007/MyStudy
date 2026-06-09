-   两边扫描
-   从左到右扫描，去除多余的右括号
-   从右到左扫描，去除多余的左括号



```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        left_num = 0
        ans = list(s)
        length = len(ans)

        for index, c in enumerate(ans):
            if c == ")":
                if left_num > 0:
                    left_num -= 1
                else:
                    ans[index] = ""
            elif c == "(":
                left_num += 1
        if left_num > 0:
            right_num = 0
            for i in range(length - 1, -1, -1):
                if ans[i] == "(":
                    if right_num > 0:
                        right_num -= 1
                    else:
                        ans[i] = ""
                elif ans[i] == ")":
                    right_num += 1
        return "".join(ans)
```


