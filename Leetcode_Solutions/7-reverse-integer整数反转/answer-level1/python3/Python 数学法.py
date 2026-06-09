### 解题思路
借鉴官方题解的思路，从C++版本改写为Python，初学Python，希望能和大家交流。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        temp1 = abs(x)
        while(temp1 != 0):
            pop = temp1%10
            temp1 = temp1//10
            
            if((rev > ((2**31)-1)//10) or ((rev == ((2**31)-1)//10) and (pop >7))):
                return 0
            if((rev <(-(2**31)//10)) or ((rev == (-(2**31)//10)) and (pop < -8))):
                return 0
            rev = rev*10 + pop
        if(x>0):
            return rev
        if(x<0):
            return -rev
        return 0
```