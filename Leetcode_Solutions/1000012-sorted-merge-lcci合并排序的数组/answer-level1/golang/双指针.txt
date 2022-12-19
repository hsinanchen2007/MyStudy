### 解题思路
此处撰写解题思路

### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    stack:=make([]int,m+n)
    k:=0
   i,j:=0,0
   for i<m && j<len(B){
       if A[i]>B[j]{
           stack[k]=B[j]
           k++
           j++
       }else if A[i]<B[j]{
           stack[k]=A[i]
           k++
           i++
       }else{
            stack[k]=A[i]
            i++
            k++
            stack[k]=B[j]
            k++
            j++
       }
   }
   for  i<m{
       stack[k]=A[i]
       k++
       i++
   }
    for  j<len(B){
     stack[k]=B[j]
     k++
     j++
   }
   for i:=0;i<len(stack);i++{
       A[i]=stack[i]
   }
  
}
```