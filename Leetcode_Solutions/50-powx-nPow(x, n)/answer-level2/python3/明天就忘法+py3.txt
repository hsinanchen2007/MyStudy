### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
           x=1/x
           n=-n
        ans=1
        while n:
            # 当合成的个数是奇数时，需要舍弃一个来保存，剩下的继续合成
            if n&1:
                ans*=x
            # 表示折中 比如n=6,x=2。 2,2,2,2,2,2
            # x*x之后 变成4，4，4 多了一个4 ans=4 则需要保存起来，剩下的2个4需要合成16
            # 2个4合成 1个16  ans=4*16=64  
            # 
            x*=x
            n>>=1
        return ans  
    
```