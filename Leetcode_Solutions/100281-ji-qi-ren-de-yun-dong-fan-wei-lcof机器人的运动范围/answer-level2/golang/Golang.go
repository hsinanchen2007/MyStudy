### 代码

```golang
func movingCount(m int, n int, k int) int {
    moved,count:=make([]bool,m*n),0
    var move func(i,j int)
    move=func(i,j int){
        if i<m&&j<n&&i>=0&&j>=0&&(i%10+i/10+j%10+j/10)<=k&&!moved[i*n+j]{
            count++
            moved[i*n+j]=true
            move(i+1,j)
            move(i,j+1)
            move(i-1,j)
            move(i,j-1)
        }
    }
    move(0,0)
    return count
}
```