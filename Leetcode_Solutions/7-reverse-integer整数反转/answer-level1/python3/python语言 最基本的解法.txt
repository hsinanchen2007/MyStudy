### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        
        
        flag = 1   # 判断正负
        if(x<=0):
            flag = 0
            x = -1 * x
    
        
        temp = 0
        while (x<-9 or x>9):
            x_end = x%10
            temp = temp*10 + x_end
            x = x//10
        
        temp = temp*10 + x

        if temp>= 2**31:
            return 0

        if(flag == 0):
            temp = -1 * temp

        return temp
```