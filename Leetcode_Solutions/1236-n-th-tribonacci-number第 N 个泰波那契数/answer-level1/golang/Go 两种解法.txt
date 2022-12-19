思路1：递归计算Tn+3 = Tn + Tn+1 + Tn+2，用map保存计算每个n值对应的计算结果避免重复计算。
```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了100.00%的用户
```
```Go []
func tribonacci(n int) int {
    nm := make(map[int]int)
    var trib func(n int) int
    trib = func(n int) int{
        switch n{
            case 0:
                return 0
            case 1,2:
                return 1
            default:
                if v,ok := nm[n];ok{
                    return v
                }
                v := trib(n-1)+trib(n-2)+trib(n-3)
                nm[n] = v
                return v            
        }
    }
    return trib(n)
}
```

思路2：从T0开始循环向上相加直到得到Tn值。
```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2 MB, 在所有 Go 提交中击败了100.00%的用户
```
```Go []
func tribonacci(n int) int {
    ns := make([]int,n+1)
    ns[0] = 0
    if n >= 2{
        ns[1],ns[2] = 1,1
    }else if n>=1{
        ns[1] = 1
    }
    for i:=3;i<=n;i++{
        ns[i] = ns[i-3]+ns[i-2]+ns[i-1]
    }
    return ns[n]
}
```
