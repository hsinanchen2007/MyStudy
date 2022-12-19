### 解题思路
挖掘出是 斐波那契数列这一隐含条件！

### 代码

```golang
func numWays(n int) int {
    if n == 0 || n == 1 {
        return 1
    }
    a, b := 0, 1
    m := 1000000007
    for i := 0; i < n; i++{
        a, b = b%m, (a+b)%m
    } 

    return b
}
```