遍历一遍s，对s中的每一个字符，用replace函数在t中找到并删除，返回t
replace() 第三个参数代表最大替换次数

```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in s:
            t = t.replace(i,'',1)
        return t
```
