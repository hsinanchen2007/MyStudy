### 解题思路
小于等于0的为false，剩下的一直除4，判断一下是不是4的整数倍，结果如果为1，返回True

### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num<=0:
            return False
        while num!=1:
            if num%4!=0:
                return False
            num/=4
        return True

     
```