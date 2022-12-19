参考大神的方法写了一下
```
class Solution:
    def reachNumber(self, target):
        #正着走反着走是一样的
        #所以只考虑正着走就可以
        #当走的距离大于target时如果（距离-target）差为偶数
        #即说明在（0，num）之间只要有一个数倒退即可
        #因为倒退就是减去该数的两倍
        num,distance = 0,0#步数，距离
        target = abs(target)#目标进行绝对值化
        while True:
            if distance>=target and (distance-target)%2==0:
                return(num)
            num+=1
            distance = distance+num
```
