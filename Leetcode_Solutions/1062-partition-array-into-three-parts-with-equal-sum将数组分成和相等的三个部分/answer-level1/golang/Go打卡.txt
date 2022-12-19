### 解题思路
此处撰写解题思路

### 代码

```golang
func canThreePartsEqualSum(A []int) bool {
    if len(A) < 3 {
        return false
    }
    var (
        l = 1
        r = len(A)-2
        ls = A[0]
        rs = A[len(A)-1]
        ms = 0
        onethird = 0
    )
    for i := 1; i < len(A)-1; i ++ {
        ms += A[i]
    }
    if (ms+ls+rs) %3 != 0 {
        return false
    }
    onethird = (ms+ls+rs) / 3
    for l < r && ls != onethird {
        ls += A[l]
        ms -= A[l]
        l ++
    }
    if l > r {
        return false
    }
    for l < r && rs != onethird {
        rs += A[r]
        ms -= A[r]
        r --
    }
    if l > r || ms != onethird {
        return false
    }
    return true
}
```