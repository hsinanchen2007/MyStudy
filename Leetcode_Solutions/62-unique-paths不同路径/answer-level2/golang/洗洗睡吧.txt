### 代码

```golang
func uniquePaths(m int, n int) int {
    a:=make([][]int,m+1)
    for i:=0;i<=m;i++{
        a[i]=make([]int,n+1)
    } 
    a[1][0]=1
    for i:=1;i<=m;i++{
        for j:=1;j<=n;j++{
            a[i][j]=a[i-1][j]+a[i][j-1]
        }
    }
    return a[m][n]
}
```