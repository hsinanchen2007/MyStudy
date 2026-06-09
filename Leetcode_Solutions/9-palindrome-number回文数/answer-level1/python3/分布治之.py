核心思路：将数字原地翻转后，看是否和原来一样即可

1. 负数肯定不行
2. 0可行
3. 正数可能行



按情况分别列出相应代码

```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x == 0:
            return True
        else:
            sx = str(x)
            return sx == sx[::-1]
```


检查后，前两项可以优化掉

```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        sx = str(x)
        return sx == sx[::-1]
```
