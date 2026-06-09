### 解题思路
先利用split函数将字符串分割，然后针对分割后的字符串，删除其中的''，最后倒序连接，倒序使用切片[::-1]来实现

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        strlist = s.split(" ")  # 依据空格来分割字符串
        while "" in strlist:  # 注意这里是""而不是" "
            strlist.remove("")  # 删掉列表中所有的空
        return (" ".join(strlist[::-1]))
```