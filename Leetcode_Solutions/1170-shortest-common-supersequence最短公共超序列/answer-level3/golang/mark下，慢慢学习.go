完全看不懂啊~~ [抄大佬的作业](https://leetcode-cn.com/u/caigogo)

```go
func shortestCommonSupersequence(str1 string, str2 string) string {
    n := len(str1)
    m := len(str2)
    f := make([][]int, n+1)
    a := make([][]int, n+1)
    for i := 0; i <= n; i++ {
        f[i] = make([]int, m+1)
        a[i] = make([]int, m+1)
    }
    for i := 0; i <= n; i++ {
        for j := 0; j <= m; j++ {
            f[i][j] = i + j
            a[i][j] = 0
        }
    }
    f[0][0] = 0
    for i := 0; i <= n; i++ {
        f[i][0] = i
    }
    for i := 0; i <= m; i++ {
        f[0][i] = i
    }
    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            if str1[i-1] == str2[j-1] {
                if f[i][j] > f[i-1][j-1] + 1{
                    f[i][j] = f[i-1][j-1] + 1
                    a[i][j] = 1
                }
            }
            if f[i][j] > f[i-1][j] + 1 {
                f[i][j] = f[i-1][j] + 1
                a[i][j] = 2
            }
            if f[i][j] > f[i][j-1] + 1{
                f[i][j] = f[i][j-1] + 1
                a[i][j] = 3
            }
        }        
    }
    ans := []byte{}
    x := n
    y := m
    for a[x][y] != 0 {
        if a[x][y] == 1 {
            ans = append(ans, str1[x-1])            
            x -= 1
            y -= 1
        } else if a[x][y] == 2 {
            ans = append(ans, str1[x-1])
            x -= 1
        } else if a[x][y] == 3 {
            ans = append(ans, str2[y-1])
            y -= 1
        }
    }
    for i := x -1; i >= 0; i-- {
        ans = append(ans, str1[i])
    }
    for i := y-1; i >= 0; i-- {
        ans = append(ans, str2[i])
    }
   // fmt.Println(f[n][m])
    return string(reverse(ans))
}

func reverse(b []byte) []byte {
    ans := []byte{}
    for i := 0; i < len(b); i++ {
        ans = append(ans, b[len(b)-1-i])
    }
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```