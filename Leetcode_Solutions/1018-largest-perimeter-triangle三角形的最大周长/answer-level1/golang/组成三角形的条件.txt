### 解题思路
三角形边长分别为：a b c
则满足 a + b > c , a - b < c

### 代码

```golang
func largestPerimeter(A []int) int {
    sort.Ints(A)
    for i := len(A) -1 ; i >= 2 ; i-- {
        if A[i] + A[i - 1] > A[i - 2] && A[i] - A[i - 1] < A[i - 2]{
            return A[i] + A[i- 1] + A[i - 2]
        }
    }
    return 0
}
```