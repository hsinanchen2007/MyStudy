### 解题思路
s1 s2判断是否字符相同
diff为余数

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        s1 = str1 + str2
        s2 = str2 + str1
        l1 = 0
        l2 = 0
        if s1 != s2:
            return ''
        if len(str1) > len(str2):
            diff = len(str1) % len(str2)    #求余数
            if diff == 0:return str2        #余数为零，返回长度小的
            str1 = str1[:diff]
        elif len(str1) < len(str2):
            diff = len(str2) % len(str1)
            if diff == 0:return str1
            str2 = str2[:diff]
        else:
            return str1
        return self.gcdOfStrings(str1,str2)

```