![image.png](https://pic.leetcode-cn.com/cac2150caabebf4a9d33e77ad8af76876c01466b3701f86c3e73ce09fa972cd0-image.png)

### 解题思路
1是处理正负，运算前全转正。
2是越界，只有除数为1的时候才会越。
3是使用移位操作加速

### 代码

```golang
func divide(dividend int, divisor int) int {
    isFu := false
    if dividend < 0{
        isFu = !isFu
        dividend = 0 - dividend
    }
    if divisor < 0 {
        isFu = !isFu
        divisor = 0 - divisor
    }
    if divisor==1{
        if isFu{
            dividend = 0-dividend
        }
       if dividend > (1<<31-1) || dividend < (0-1<<31){
            return 1<<31-1
        }
        return dividend
    }

    count := 0
    threhold := 31
    for dividend >= divisor{
        for dividend - divisor<<threhold < 0 && threhold >=0{
            threhold--
        }
        dividend -=divisor<<threhold
        count += 1<<threhold
    }

    if isFu{
       count = 0-count 
    }

    return count
}
```