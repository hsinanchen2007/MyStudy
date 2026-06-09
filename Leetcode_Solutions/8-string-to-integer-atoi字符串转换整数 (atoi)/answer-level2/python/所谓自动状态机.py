### 解题思路
此处撰写解题思路

### 代码

```python3
INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31
class Solution:
    def myAtoi(self, str: str) -> int:
        ##start 0 signed 1 num 2 end 3
        state = 0
        ##signal 0 +  1 -
        signal = 0
        ans = 0
        for i in str:
            if state == 0:
                if i==' ':
                    state = 0
                elif i=='+' or i=='-':
                    state = 1
                    signal = 1 if i=='-' else 0
                elif i.isdigit():
                    state = 2
                    ans = ans*10 + int(i)
                else:
                    state = 3
            elif state == 1:
                if i.isdigit():
                    state = 2
                    ans = ans*10+int(i)
                else:
                    state = 3
            elif state == 2:
                if i.isdigit():
                    state = 2
                    ans = ans*10+int(i)
                else:
                    state = 3
            else:
                state = 3
        
        if signal==0:
            ans = min(INT_MAX,ans)
        else:
            ans = max(INT_MIN,-ans)
        return ans
        
```