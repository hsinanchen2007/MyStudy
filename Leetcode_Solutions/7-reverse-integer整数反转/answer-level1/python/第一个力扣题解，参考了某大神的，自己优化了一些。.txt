### 解题思路
此处撰写解题思路

### 代码
简单的字符串反转问题；执行用时超过99.13%；执行内存超过99.88%的用户
```python3
class Solution:
    def reverse(self, x: int) -> int:
        str_x=str (x)
        #len_str=len (str_x)
        if str_x[0]=='-':
            str_y=str_x[len(str_x):0:-1]
            y=0-int (str_y)
            if y<-2**31:
                y=0
            
        elif str_x=='0':
            y=0
        else:
            str_y=str_x[::-1]
            y=int (str_y)
            if y>2**31-1:
                y=0
        return y
        

```