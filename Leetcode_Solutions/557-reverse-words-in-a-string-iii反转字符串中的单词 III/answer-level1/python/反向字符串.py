### 解题思路
此处撰写解题思路

反向切片和str.split(" ")

如何手动无错
要确定定义域和最简单的无错例子运行


### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        res = ""
        f = s.split(" ")
        for i in f:
            res+=i[::-1]
            res+=" "
        
        return res[:-1]

```