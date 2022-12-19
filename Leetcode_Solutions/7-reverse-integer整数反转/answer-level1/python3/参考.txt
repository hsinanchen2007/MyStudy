### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x<0:
            x=x-x*2
            if -int(str(x)[::-1])<-2**31:
                return 0
            else:
                return -int(str(x)[::-1])
        elif x==0:
            return 0
        else:
            if int(str(x)[::-1])>2**31-1:
                return 0
            else:
                return int(str(x)[::-1])
```