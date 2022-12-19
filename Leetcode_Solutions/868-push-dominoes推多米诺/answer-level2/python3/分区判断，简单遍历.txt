

-   首先在首部添加一个"L"，尾部添加一个"R"
-   "L"和"R"供会产生4种组合：

```
L ... R  => L ... R
R ... R  => R RRR R
R ... L  => R R.L L
L ... L  => L LLL L
```

如上所示，只需要对上面的第三种情况额外判断一下奇偶即可



```python
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        ans = ""

        temp = "L" + dominoes + "R"
        left = 0
        for i in range(1, len(temp)):
            if temp[i] in ("L", "R"):
                if temp[left] == "L" and temp[i] == "L":
                    ans += "L" * (i - left - 1) + temp[i]
                elif temp[left] == "R" and temp[i] == "L":
                    length = i - left - 1
                    half = length // 2
                    if length % 2:
                        ans += "R" * half + "." + "L" * half
                    else:
                        ans += "R" * half + "L" * half
                    ans += temp[i]
                elif temp[left] == "L" and temp[i] == "R":
                    ans += temp[left + 1:i + 1]
                elif temp[left] == "R" and temp[i] == "R":
                    ans += "R" * (i - left - 1) + "R"

                left = i

        return ans[:-1]
```


