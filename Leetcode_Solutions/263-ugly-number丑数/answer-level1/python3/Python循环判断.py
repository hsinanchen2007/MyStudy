对num，遍历集合x，如果不能被2或3或5整除，返回False，否则更新num继续判断。
```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False
        x={2,3,5}
        while num!=1:
            for i in x:
                if num%i==0:
                    num//=i
                    break
            else:
                return False
        return True
```
