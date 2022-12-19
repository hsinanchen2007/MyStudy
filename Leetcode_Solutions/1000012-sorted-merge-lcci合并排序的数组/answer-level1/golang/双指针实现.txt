## 双指针实现（和实现链表合并方法一样）

```
//双指针实现
func merge(A []int, m int, B []int, n int)  {
    C:=make([]int,m)
    copy(C,A[0:m])
    p,q:=0,0
    index:=0
    for p<m && q<n{
        if C[p] < B[q]{
            A[index]=C[p]
            index++
            p++
        }else{
            A[index]=B[q]
            index++
            q++
        }
    }
    for p==m && q<n{
        A[index]=B[q]
        index++
        q++
    }
    for q==n && p<m{
        A[index]=C[p]
        index++
        p++
    }
}
```
