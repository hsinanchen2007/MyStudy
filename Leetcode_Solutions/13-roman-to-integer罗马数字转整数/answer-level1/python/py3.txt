### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0
        temp = 0
        _dict ={
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        for i in s:
            if temp == 0:
                temp = _dict[i]
            elif _dict[i] >temp:
                result -= temp
                temp = _dict[i]
            else:
                result += temp
                temp = _dict[i]
        return result + _dict[s[-1]]
```