代码如下
```
class Solution:
    def mySqrt(self,x) :
        ori = x   #初始化
        upp = 0
        low = 0
        if x > 10:  # 10是随便取的，大一点就先取一次整，不大就直接用
            low = x//2
        else:
            low = x

        while low**2>ori:   # 确定上下边界。
            upp = low       # 即不断进行 x//2 ，一定有一个时刻达到取整之前那个数的平方大于original ， 取整之后平方小于original
            low = low // 2  #（例如original = 8, 当8//2=4时4^2=16>8，但继续做4//2的话=2,2^2=4<8，则upp=4，low=2）
            
        if upp-low == 1:    # 进行一波判断
            return low
        if low**2 == ori:
            return low 
        elif upp**2 == ori:
            return upp
        
        mid = (upp+low)//2  # 对上下边界继续进行二分法
        while upp-low!=1:   # 当上下边界相差为1时，直接返回下边界就行了
            if mid**2>ori:
                upp = mid
                mid = (upp+low)//2
            else:
                low = mid  
                mid = (upp+low)//2 
        return low  
```

以上
