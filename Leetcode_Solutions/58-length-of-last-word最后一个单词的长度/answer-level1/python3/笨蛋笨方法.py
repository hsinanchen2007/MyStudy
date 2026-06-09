### 解题思路
首先，网页的编码器本身有些问题；
方法的话就是直接进行空格切割，然后数数组中最后一个非空的元素长度就好啦

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split(" ")
        if a == "" or not a:
            return 0
        c = ""
        for i in a:
            if not len(i) == 0:
                 c = i
        l = len(c)

        return l
```