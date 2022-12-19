### 解题思路
题目简单，需要注意的几种情况，x的正负，最后一位数是否是0，是否超出32位范围，用了几个if else规则解决。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:

       
        if str(x)[-1] == 0:
            string = str(x)[:-1]
        else:
            string = str(x)
            
        if x<0:
            
            b = string[1:]
            b = b[::-1]
            b = -int(b)
            if b<-2**31 or b>2**31-1:
                return 0
            else:
                return b
        else:
            b = string
            b = b[::-1]
            b = int(b)
            if b<-2**31 or b>2**31-1:
                return 0
            else:
                return b
            
```