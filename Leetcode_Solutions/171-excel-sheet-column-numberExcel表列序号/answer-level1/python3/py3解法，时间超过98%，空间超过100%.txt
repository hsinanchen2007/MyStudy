### 解题思路
我把这题翻译一下：A=1，B=2，AB=1 * 26^1 + 2 * 26^0；要是还没懂什么意思的话，你记得怎么把二进制数转换为十进制吗：1011=1 * 2^3+0 * 2^2+1 * 2^1+1 * 2^0 ;现在无非给你变了个样子，换了个皮！
只需要再用字典把字母映射成数字即可

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str):
        dict={}
        for i in range(26):
            dict[chr(ord('A')+i)]=i+1
        res=0
        f=0
        for i in reversed(s):
            res+=dict[i]*26**(f)
            f+=1
        return res
```