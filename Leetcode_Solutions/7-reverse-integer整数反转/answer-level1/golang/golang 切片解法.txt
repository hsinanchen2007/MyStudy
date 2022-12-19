### 解题思路
观察输入及输出可得出，可以采用切片存储每一位数，
先对原数字取余加入切片
再对原数字减位
顺便计算倍数


### 代码

```golang
import (
	"math"
)

func reverse(x int) int {
    slice := make([]int,0)
    var time,sum int 
    for{
        slice = append(slice, x % 10 )
        x = x / 10
        if (x == 0){
            break
        }
        time++
    }
    for _, a := range slice{
        sum +=  int(math.Pow10(time)) *  a
        time--
    }
    if sum > int(math.Pow(2,31)) - 1 || sum < int(math.Pow(-2,31)) {
        return 0
    }
    return sum 
}
```