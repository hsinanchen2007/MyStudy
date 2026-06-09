### 解题思路
逆向遍历

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    index := m+n-1
    m--
    n--
    for m>=0 && n>=0{
        if A[m] > B[n]{
            A[index] = A[m]
            m--
        }else{
            A[index] = B[n]
            n--
        }
        index--
    }

    if n >= 0{
        for i:=0;i<=n;i++{
            A[i] = B[i]
        }
    }

}
```