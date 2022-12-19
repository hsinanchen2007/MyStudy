### 解题思路
此处撰写解题思路

### 代码

```golang
func climbStairs(n int) int {
    if n == 0 {return 0}
    if n == 1 {return 1}
    if n == 2 {return 2}
    p := [][]int{{1,1}, {1,0}}
    res := [][]int{{1,1}, {1,0}}
    for i:= n-1; i >0 ; i = i/2 {
        if i%2 == 1 {
            res = pow(res, p)
        }
        p = pow(p, p)
    }
    return res[0][0]

}

func pow(a [][]int, b [][]int) [][]int {
    var c = [][]int{{0,0}, {0,0}}
    for i:=0; i< len(a);i++ {
        for j:=0; j< len(a[i]); j++ {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]
        }
    }
    return c
}
```