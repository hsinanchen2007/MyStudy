### 解题思路
（1）判断输入的字符串的长度是否为奇数，如果是奇数，则直接返回False
 (2) 创建一个字典，将左边括号作为字典的key, 右边的括号作为value
 (3) 创建一个列表l_str，以s的长度作为循环次数，每次循环，向l_str 中添加一个字符，当l_str的长度大于2 时，查询l_str[-1]和l_str[-2]是否时一对括号，如果是，则用pop()函数在l_Str中删掉这两个数，如果不是则进行下一层循环。最后return l_str==[],如果括号全部匹配，则l_str==[]为True，否则为False
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        length = len(s)
        l_str = []
        dic= {'(':')','{':'}','[':']'}
        if length%2 ==1:
            return False
        else:
            
            for i in range(0,length):
                l_str.append(s[i])
                if len(l_str)>=2:
                    if l_str[-2] in dic.keys():
                        k = l_str[-2]
                        if l_str[-1] == dic[k]:
                            l_str.pop()
                            l_str.pop()
            return l_str==[]
```