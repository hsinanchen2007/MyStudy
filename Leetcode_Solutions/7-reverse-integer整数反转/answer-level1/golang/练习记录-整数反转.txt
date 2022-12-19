### 解题思路
这就是为什么学习算法
func reverse(x int) int {
    y := 0
    for x!=0 {
        y = y*10 + x%10
        if !( -(1<<31) <= y && y <= (1<<31)-1) {
            return 0
        }
        x /= 10
    }
    return y
}

作者：elliotxx
链接：https://leetcode-cn.com/problems/reverse-integer/solution/0ms-11-xing-dai-ma-go-shi-xian-by-elliotxx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 代码

```golang
func reverse(x int) int {
    var res int
    midSlcie := make([]int,0)
    if x >=0{
        for{
            if x >= 10{
            midSlcie = append(midSlcie, x % 10)  
            x = x / 10
            }else{
                midSlcie = append(midSlcie, x)
                break
            }
        }
    }else{
             for{
            if -x >= 10{
            midSlcie = append(midSlcie, -x % 10)  
             x = x / 10
            }else{
                midSlcie = append(midSlcie, -x)
                break
            }
        }
    }
    //将数切片中的数据反转恢复
    for k, v := range midSlcie{
        //计算每一位并求和
        for i := 0; i < len(midSlcie)-k-1; i++{
            v *= 10
        }
        res = res + v
    }
    if x < 0{
        res = -res
    }
    if res > 2147483648 || res < -2147483648{
        return 0
    }
    return res
}
```