### 解题思路
位运算

### 代码
//位运算，从0开始算，不用循环又重复算之前的 //TODO加个过程更易理解
```golang
func countBits(num int) []int {
    res := make([]int,num+1)
    res[0] = 0
    for i:=1;i <= num;i++{
        res[i]= res[i&(i-1)] + 1
    }
    return res
}
```

//暴力直接求每个数的
```
func countBits(num int) []int {
    res := make([]int,num+1)
    for i:=0;i <= num;i++{
        n:= 0
        v := i
        for v > 0 {
            n++
            v = v&(v-1)
        }
        res[i]= n
    }
    return res
}
```

