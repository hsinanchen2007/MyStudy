按照空格`split()`切片后对list`[::-1]`取反，用空格再接起来，然后`strip()`去除头部和尾部的空格。相信稍微了解过爬虫或nlp方向的都会对正则及这些操作很熟悉，只是觉得这样太投机取巧。。。
```
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1]).strip()
```
