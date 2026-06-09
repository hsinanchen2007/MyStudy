```
func minIncrementForUnique(A []int) int {
      sort.Ints(A)
    
       num:=0
     
     for i:=0;i<len(A)-1;i++{
        j:=i+1
         if A[j]<=A[i]{
          
            num+=A[i]+1-A[j]
             A[j]=A[i]+1
         }
     }
     return num
     }
```
