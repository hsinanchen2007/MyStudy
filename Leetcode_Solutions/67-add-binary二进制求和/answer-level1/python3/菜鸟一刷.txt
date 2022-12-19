### 解题思路
头脑不清醒，写的毫无美感，变量太多

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        A = int(a)
        B = int(b)
        C = A+B
        if C==0:
            return "0"
        m = 0
        D = 0
        i = 0
        s=""
        while C != 0:
            i = i+1
            if ((C+m) % 10 == 3):
                D = D+1*10 ^ (i)
                m = 1
                s="1"+s
            elif ((C+m) % 10 == 2):
                D = D
                m = 1
                s="0"+s
            elif ((C+m) % 10 == 1):
                D = D+1*10 ^ (i)
                m = 0
                s="1"+s
            else:
                D = D
                m = 0
                s = "0"+s
            C = C//10
        if m == 1:
            return ("1"+s)
        else:
            return (s)
            

            
            

```