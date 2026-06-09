### 解题思路
此处撰写解题思路

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    A = append(A[:m],B...)
    FastSort(A)
}

func FastSort(A []int){
    var i,j = 0,len(A)-1
    for i<j{
        if A[j] > A[0]{
            j--
            continue
        }
        if A[i] <= A[0]{
            i++
            continue
        }        
        A[i],A[j] = A[j],A[i]
    }
    A[0],A[j] = A[j],A[0]
    if len(A[:j]) >1 {
        FastSort(A[:j])
    }
    if len(A[j+1:]) >1 {
        FastSort(A[j+1:])
    }
    
}
```