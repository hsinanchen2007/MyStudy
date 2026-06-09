```
class Solution:
    def reverse(self, x: int) -> int:
        tube = []
        flag = 1
        if x<0:
            flag = -1
            x=abs(x)
        while x:
            tube.append(x%10)
            x = x//10
        result = 0
        for i in tube:
            result = result*10+i
            if result*flag < -2 ** 31 or result*flag > 2 ** 31 - 1:
                return 0
        return result*flag
```
![image.png](https://pic.leetcode-cn.com/18c46824a25b84ab0d79444baccf6aec9cbbec3fbb3ad1ef0632c3b5fa88e80e-image.png)
```class Solution:
    def reverse(self, x: int) -> int:
        flag = 1
        result=0
        if x<0:
            flag = -1
            x=abs(x)
        while x:
            result = result*10+x%10
            if result*flag < -2 ** 31 or result*flag > 2 ** 31 - 1:
                return 0
            x = x//10
        return result*flag
```

![image.png](https://pic.leetcode-cn.com/ad16eb5c2b79c1618dba66ccdaa2de9c9f6e25733dcedd7a13fe4c9f3fbece0c-image.png)
为什么第二种用时反而会更长？