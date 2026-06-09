# 解题思路
- ## 快速幂
 	- 快速幂可以用位运算来实现

 	 	-  n & 1  —  取n的二进制数最低位 , n & 1 =1 ，n为奇数，=0 为偶数 ,相当于 n % 2==0

 	 	-  n >> 1 —右移1位, 去掉 n 的二进制数最低位  , 相当于 n / 2  

 		- 当 n 为偶数时
 		 	-  x ^ n =  x ^( n / 2 ) * x ^( n / 2 ) 
 		 	-  n >> 1 , n右移 1 位后，x 自己乘自己，因为二进制每位的差距是平方关系
 		- 当 n 为奇数时
 		 	- 需要再乘以多出来的一次，即 x ^ n = x * x ^( n - 1 )
 			- n - 1 , x 不更新，将 x 累乘到 ret
---
# 解法一:递归
--执行用时：0 ms --内存消耗：2 MB
```go
func myPow(x float64, n int) float64 {
    if n == 0{
        return 1
    }
    if n == 1{
        return x
    }
    if n<0{
        x = 1/x
        n = -n
    }
    temp := myPow(x , n/2)
    if n%2 == 0{
        return temp*temp
    }
    return x*temp*temp
}
```

---
# 解法二:迭代
--执行用时：0 ms --内存消耗：2 MB

```go
func myPow(x float64, n int) float64 {
    if n == 0{
        return 1
    }
    if n == 1{
        return x
    }
    if n<0{
        x = 1/x
        n = -n
    }
    ret:=1.0
    for n>=1{
        if n & 1 == 1{
            ret *= x
            n--
        }else{
            x *= x
            n = n >> 1
        }
    }
    return ret
}
```
