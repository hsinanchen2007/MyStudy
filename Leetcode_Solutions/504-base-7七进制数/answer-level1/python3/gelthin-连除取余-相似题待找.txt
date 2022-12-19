### 解题思路
这一题简单做法，连除然后取模。
代码比较简单，就是下面的 while num>0 这里我有一些记不清，很怕错了。

有很多道相似的题目，例如：暂时还没找到

先前不知道在哪里看到的写法，避免后续仍然需要反转字符串，可以写
res = "a" + res

而不是常规的 res += "a"

### 代码

```python3
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        sgn = 1
        if num < 0:
            num = -num
            sgn = -1
        res = ""
        while num>0:
            res = str(num%7) + res   #先前不知道在哪里看到的别人的写法， 避免反转字符串
            num = num//7
        if sgn == -1:
            res = "-" + res
        return res
```