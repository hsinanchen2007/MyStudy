### 解题思路
此处撰写解题思路

### 代码

```golang
func minIncrementForUnique(A []int) int {
    sort.Ints(A)
    var nums int
    for i:= 0 ;i<len(A)-1;i++ {
        if A[i] >= A[i+1] {
            nums += (A[i]-A[i+1] +1)
            A[i+1] += (A[i]-A[i+1] +1)
        }
    }

    return nums
}
```