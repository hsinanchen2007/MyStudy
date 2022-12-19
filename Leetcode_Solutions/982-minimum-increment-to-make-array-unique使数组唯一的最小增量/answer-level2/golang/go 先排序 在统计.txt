### 解题思路
go 先排序 在统计 
由于0 <= A.length <= 40000
0 <= A[i] < 40000
只可能出现[0,40000]个数
计数排序为线性时间

### 代码

```golang
func minIncrementForUnique(A []int) int {
    B := make([]int, len(A))
    CountingSort(A, B, 40000)
    res := 0
    for i := 1; i < len(B); i++  {
        if B[i] <= B[i-1] {
            res += B[i-1] - B[i] + 1
            B[i] = B[i-1] + 1
        }
    }

    return res

}

func CountingSort(A, B []int, k int) {
    C := make([]int, k)
    // counting every num count
    for _, j := range(A){
        C[j] = C[j] + 1
    }

    // counting <= numi's count
    for i := 1; i < k; i++ {
        C[i] = C[i] + C[i-1]
    }

    for j := len(A)-1; j>=0; j-- {
        C[A[j]] = C[A[j]] - 1
        B[C[A[j]]] = A[j]
    }
}
```