```
func reverse(x int) int {
    if x < 0 {
        return -reverse(-x)
    }
    
    var newNum int
    for x != 0 {
        newNum = newNum*10 + x%10
        x /= 10
    }
    
    if newNum < 0x7fffffff {
        return newNum
    }
    return 0
}
```

思路：
如果输入是负数，就递归调用原函数，是参数变为 -x，newNum为最终转换后的结果，初始值为0，x%10 表示取出最后一位数，并作为当前位的最高位。然后判断newNum是否溢出，若溢出，则返回0.
