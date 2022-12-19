
-   快慢步法

```
我们的目的是让剩余的字符数量一致，这样就能相互间各取值，只需要让长的每次走两步，短的走一步，最后短的就有可能追上长的，根据这个来构造
```

-   如果两个长度一致，直接每个字符相互间隔，返回结果
-   长度不一致
    -   长的前进步伐为2
    -   短的前进步伐为1
    -   如果两个步伐相同，更新结果，剩余字符每个字符相互间隔
-   剩余的字符更新到结果中即可



```python
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A == B:
            return "ab" * A

        ans = ""

        la = A
        lb = B

        while la > 0 and lb > 0:
            if la > lb:
                ans += "aab"
                la -= 2
                lb -= 1
            elif la < lb:
                ans += "bba"
                la -= 1
                lb -= 2
            else:
                if A > B:
                    ans += "ab" * la
                else:
                    ans += "ba" * la
                la = 0
                lb = 0
        if A > B:
            ans += "a" * la + "b" * lb
        else:
            ans += "b" * lb + "a" * la

        return ans
```


