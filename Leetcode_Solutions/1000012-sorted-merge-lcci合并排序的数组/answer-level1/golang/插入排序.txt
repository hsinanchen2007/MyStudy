### 解题思路
打卡

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    for i:=0;i<n;i++{
        A[i+m]=B[i]
    }
    for i:=m;i<m+n;i++{
        for j:=i-1;j>=0;j--{
            if A[j]>A[j+1]{
                A[j],A[j+1]=A[j+1],A[j]
            }else{
                break
            }
        }
    }
}
```