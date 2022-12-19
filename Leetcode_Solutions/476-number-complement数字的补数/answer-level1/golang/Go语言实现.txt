主要思路如下：
```
>  先获得nums的有效二进制位长度length
>  然后用一个变量res存储将目标数据进行按位取反后的值
>  将res的低length位清零（先右移length位，再左移length位）
>  ^nums与res的差就是所求结果

```
```
func findComplement(num int) int {
    var res int
    var length uint

    for temp := num;temp !=0;length++{
        temp >>=1
    }
    
    res = ^num >> length
    res = res << length
    res = ^num - res
    return res
}
```
