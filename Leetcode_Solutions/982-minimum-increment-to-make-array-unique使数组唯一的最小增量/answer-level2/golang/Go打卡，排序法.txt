### 解题思路
此处撰写解题思路

### 代码

```golang
func minIncrementForUnique(A []int) int {
    if len(A) == 0 {
        return 0
    }
    var count int
    var debt int
    sort.Ints(A)
    for i := 1; i < len(A); i ++ {
        if A[i-1] == A[i] {
            count -= A[i]
            debt ++
        }else if A[i-1] < A[i] {
            for j := A[i-1]+1; j < A[i]; j ++ {
                if debt == 0 {
                    break
                }
                debt --
                count += j
            }
        }
    }
    temp := A[len(A)-1]+1
    for debt > 0 {
        count += temp
        temp ++
        debt --
    }
    return count
}
```