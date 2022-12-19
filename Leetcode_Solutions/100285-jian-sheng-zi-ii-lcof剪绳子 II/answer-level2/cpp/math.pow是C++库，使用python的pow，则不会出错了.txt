### 解题思路
此处撰写解题思路
其实要注意math.pow是C++的库，如果使用math.pow会出错

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n<=3:
            return n-1
        # res=1
        # while n>4:
        #     res*=3
        #     n-=3
        # return int(res*n)%1000000007

        a,b=n//3,n%3
        if b==0:
            res=pow(3,a)
        elif b==1:
            res=pow(3,a-1)*4
        else:
            res=pow(3,a)*2
        return int(res)%1000000007
```