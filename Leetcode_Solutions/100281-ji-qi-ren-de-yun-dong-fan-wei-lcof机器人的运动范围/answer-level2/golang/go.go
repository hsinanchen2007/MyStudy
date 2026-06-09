### 解题思路
此处撰写解题思路

### 代码

```golang
func movingCount(m int, n int, k int) int {
    matrix := make([][]int,m)
    for i := range matrix{
        matrix[i] = make([]int,n)
    }
    res := 0
    color(matrix,0,0,m,n,k,&res)
    return res
}

func color(matrix [][]int, i,j,m,n,k int, res *int) {
    if matrix[i][j] != 0{
        return
    }
    *res++
    matrix[i][j] = 1
    if i < m-1 && valid(i+1,j,k){
        color(matrix,i+1,j,m,n,k,res)
    }
    if j < n-1 && valid(i,j+1,k){
        color(matrix,i,j+1,m,n,k,res)
    }
}

func valid(a,b,k int) bool{
    res := 0
    for a !=0 {
        x := a % 10
        a = (a-x)/10
        res += x
    }
    for b !=0 {
        x := b % 10
        b = (b-x)/10
        res += x
    }
    if res <=k{
        return true
    }
    return false
}
```