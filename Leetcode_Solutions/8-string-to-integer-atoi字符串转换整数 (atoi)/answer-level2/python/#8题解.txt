### 解题思路
应用有限自动机（DFA）。坐标分别为当前元素类别和目前所处状态，对应值为下一步状态。

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        state_table={'start':['start','signed','input','end'],
              'signed':['end','end','input','end'],
              'input':['end','end','input','end'],
              'end:':['end','end','end','end']}
        sign=1
        state='start'
        num=0
        element=0
        for i in str:
            if i.isspace():
                element=0
            elif i=='+'or i=='-':
                element=1
            elif i.isdigit():
                element=2
            else:
                element=3
            
            state=state_table[state][element]
            if state=='input':
                num=num*10+int(i)
            elif state=='signed':
                    if i=='+':
                        sign=1
                    elif i=='-':
                        sign=-1
            if state=='end':
                break
        if sign*num<-2**31:
            return -2**31
        elif sign*num>2**31-1:
            return 2**31-1
        else:
            return sign*num
            
            
```