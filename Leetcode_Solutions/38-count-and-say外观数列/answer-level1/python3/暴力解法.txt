### 解题思路
    用 count() 来表达一个字符串，
    遍历字符串，若后一个与前一个相同，则加入temp，若不同，则先统计此时列表中个数，以及列表中值
    将统计的个数以及值保存在result字符串中，并清空列表，进行下一次操作

    countAndSay单纯用来执行循环，此时必须先把temp 设置为1，因为第一个字符串无法被描述

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        temp = '1'
        for i in range(1,n):
            temp = self.count(temp)
        return temp
    
    def count(self, s:str) -> str:
        temp = [s[0]]
        result = ''
        for i in range(1,len(s)):
            if s[i] in temp:
                temp.append(s[i])
            else:

                result += str(len(temp)) + temp[0]
                temp = []
                temp.append(s[i])
        result += str(len(temp)) + temp[0]
        return result
                
                
```