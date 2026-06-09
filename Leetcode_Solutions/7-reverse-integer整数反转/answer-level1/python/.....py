### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        num = x
        num = str(num)
        maxnum = len(num)
        key1 = 1
        key = 0
        for i in range(0,maxnum):
            if num[i] == '-':
                key = 1
            else:
                res = res+int(num[i])*pow(10,key1-1)
                key1 += 1
        if res < -pow(2,31):
           return 0
        elif res > pow(2,31):
            return 0
        if key == 1:
           return -res
        else:
            return res
```