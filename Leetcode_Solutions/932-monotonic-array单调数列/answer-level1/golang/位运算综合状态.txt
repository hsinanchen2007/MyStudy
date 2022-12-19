### 解题思路
> 2
= 2|4
< 4

### 代码

```golang
func isMonotonic(A []int) bool {
    al := len(A)
    if al ==1 {
        return true
    }
    flag := 0

    for i := 0;i<(al-1);i++ {
        if A[i] >A[i+1] {

            if i == 0 {
                flag = 2
            }else {
                flag &= 2
            }
        }
        if A[i] == A[i+1] {
            if i == 0 {
                flag =  2|4

            }else {
                flag &= 2|4
            }
        }
        if A[i] <A[i+1] {
                        if i == 0 {
                flag =  4

            }else {
                flag &= 4
            }
        }


    }
    return flag >0

}
```