### 解题思路
不能被2整除则返回False，否则，判断最后是否为2，不是则除以2

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if(n==1):
            return True
        elif(n<=0):
            return False
        else :
            while(n%2==0):
                if(n==2):
                    return True
                else:
                    n = n/2
            return False


```