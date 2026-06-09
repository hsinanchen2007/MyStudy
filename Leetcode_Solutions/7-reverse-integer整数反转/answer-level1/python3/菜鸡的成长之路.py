### 解题思路
第六次才通过。頑張ってください。

### 代码

```python3
class Solution:
    def reverse(self, x):
        if x >=-2**31 and x < 0:
            x = abs(x)
            x = str(x)
            x = x[::-1]
            x = int(x)
            x = -1*x
            if x<-2**31:
                print(0)
                return 0
            else:
                print(x)
                return x
        elif x >= 0 and x < 2**31:
            x = str(x)
            x = x[::-1]
            x = int(x)
            if x>2**31:
                print(0)
                return 0
            else:
                print(x)
                return x
        else:
            pass
```