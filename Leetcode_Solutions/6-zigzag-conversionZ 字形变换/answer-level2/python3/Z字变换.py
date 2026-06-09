### 解题思路
我还是做题做的太少了，不过能通过已经很开心了~

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1 or len(s)<=1:
            return s
        result=""
        for row in range(numRows):
            direction=1
            idx=row
            while idx<len(s):
                result+=s[idx]
                if row==0 or row==numRows-1:
                    idx+=(numRows-1)*2
                else:
                    if direction==1:
                        idx+=2*(numRows-1-row)
                    else:
                        idx+=2*row
                    direction*=-1
        return result

            
```