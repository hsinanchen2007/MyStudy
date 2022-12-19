### 解题思路
此处撰写解题思路

### 代码

```golang
func sortArrayByParity(A []int) []int {
    // 双指针
    l := len(A)
    if l <= 1 {
        return A
    }
    i := 0
    j := l - 1
    for i < j {
        for i < l && A[i] % 2 == 0 {
            i++
        }
        for j >= 0 && A[j] % 2 == 1  {
            j--
        }
        if i < j {
            A[i], A[j] = A[j], A[i]
            i++
            j--
        }
    }
    return A
}
```