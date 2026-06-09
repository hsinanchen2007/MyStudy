### 解题思路


### 代码

```golang
func sortArrayByParity(A []int) []int {
    //思路:从头遍历，遇到奇数就与后面的偶数交换，如果无交换，直接返回
    n := len(A)
    for i:=0; i<n; i++{
        if !(A[i] % 2 == 0) { //如果是奇数
            swapped := false
            for j:=i+1;j<n;j++{
                if A[j] % 2 == 0 {
                    tmp := A[i]
                    A[i] = A[j]
                    A[j] = tmp
                    swapped = true
                    break //交换过一个就结束
                }
            }
            if !swapped {
                return A
            }
        }
    }
    return A
}
```