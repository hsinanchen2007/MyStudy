### 解题思路
因为两个瓶子所能装下水的范围是最大公约数的倍数水，考虑一下几种特殊情况
1.x=0,y=0的情况(不能用辗转相除法)
2.其他情况用辗转相除法求公约数，看z是否满足可以整除以及z<=x+y


### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x==0 and y ==0:
            if z==0:
                return (1)
            else:return (0)
        else:
            max_cal = self.first_way(x,y)
            return(z<=x+y and z % max_cal ==0)



    def first_way(self,a:int,b:int):
        if a<b:
            temp = a
            a = b
            b = temp
        while(b!=0):
            temp= a%b
            a=b
            b = temp
        return a
```