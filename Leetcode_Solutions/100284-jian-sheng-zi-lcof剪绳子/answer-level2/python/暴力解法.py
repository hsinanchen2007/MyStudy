### 解题思路
求最大值x1x2……xm的乘积最大，约束条件为x1+x2+……+xm=n:
我们中学就学过，这种条件下的最大值为x1=x2=x3……=xm时取得。
但是要求x1,x2...xm为整数，所以大胆猜想x1,x2...xm，越平均越好。PS（我证明不来，冥冥之中感觉到的。。。)
所以在已知m是多少的时候的最大值我们可以知道了。
但本题不知道m是多少，或许有好的方法可以缩小确定m的范围，再看到数据量不是很大，
感觉暴力遍历m的所有取值也能做出来。


### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        ans=0
        for m in range(2,n+1):
            t=n//m
            x=n%m
            tmp=1
            for j in range(x):
                tmp*=(t+1)
            for k in range(m-x):
                tmp*=t
            ans=max(ans,tmp)
        return ans
```