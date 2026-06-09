### 解题思路
上下翻转+对角线翻转

### 代码

```golang
func rotate(matrix [][]int)  {
    n := len(matrix)

    for i := 0; i < n/2; i++ {
        for j := 0; j < n; j++{
            Mswap(&matrix[i][j], &matrix[n-i-1][j])
        }
    }
    for i := 0; i < n; i++ {
        for j := i+1; j < n; j++ {
            Mswap(&matrix[i][j], &matrix[j][i])
        }
    }
}

func Mswap(a, b *int) {
    *a ^= *b
    *b ^= *a
    *a ^= *b
}
```