![image.png](https://pic.leetcode-cn.com/321daf11cc98a81fe72047c113df3fe54df0b6a6adf5b0f9898cf30c0a49c2ca-image.png)

先上结果，再上代码
```
func arrangeCoins(n int) int {
    var sum int = 0
    var r int = 0
    if n == 1 {
        return 1
    }
    for i:=1; i<=n; i++{
        sum += i
        if sum > n{
            r = i-1
            break
        }
    }
    return r
}
```

