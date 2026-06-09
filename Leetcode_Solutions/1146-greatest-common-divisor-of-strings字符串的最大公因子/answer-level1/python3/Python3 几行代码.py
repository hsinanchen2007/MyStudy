### 解题思路
此处撰写解题思路
代码应该一看就懂，偷了个懒，用math自带的gcd，没有自己去写。

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 != str2+str1:
            return ""
        else:
            return str1[:math.gcd(len(str1),len(str2))]


```