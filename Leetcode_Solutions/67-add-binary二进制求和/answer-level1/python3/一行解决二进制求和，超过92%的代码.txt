```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2)).replace("0b", "")
```

使用bin、int方法，以及replace方法用于去除二进制数前面的0b
效果如下：

![image.png](https://pic.leetcode-cn.com/b60a84297ff828a271d1d3cd284587bf4df14a28ca89726b8cfc4886c0f23d83-image.png)

