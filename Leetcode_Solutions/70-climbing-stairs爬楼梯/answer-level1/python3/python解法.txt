### 解题思路
排列组合，假设1有x个，2有y个，最终通过x，y和n的关系判断所有情况，通过排列组合拿到每种情况有多少种走法，加起来便是

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        x=y=1
        nn=0
        for y in range((n//2)+1):
            a1=a2=1
            x=(n-2*y)
            for i in range(x+1,x+y+1):
                a1*=i
            for j in range(1,y+1):
                a2*=j
            nn+=a1/a2
        return int(nn)
```