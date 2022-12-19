
## 思路
先将字符串按空格分割，其中每一项旋转，再组合起来，添加空格。和另外一个一行的解法不一样嗷！
## 代码
```
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([i[::-1] for i in s.split()])
```