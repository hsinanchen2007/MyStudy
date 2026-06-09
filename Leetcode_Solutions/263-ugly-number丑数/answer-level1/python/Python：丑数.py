### 解题思路
暂时没想到什么好方法……

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num==1:return True
        signal=1
        while num!=signal:
            signal=num
            if num==1:return True
            num=num//5 if num%5==0 else num
            num=num//3 if num%3==0 else num
            num=num//2 if num%2==0 else num
        return False      
```