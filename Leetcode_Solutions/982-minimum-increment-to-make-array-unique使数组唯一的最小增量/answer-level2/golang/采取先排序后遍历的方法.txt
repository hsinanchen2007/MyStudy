func minIncrementForUnique(A []int) int { 
    if len(A)==0{
        return 0
    } 
    sort.Ints(A)
    before:=A[0]
    fin:=0
    for i:=1;i<len(A);i++{
        if A[i]<=before{
       //与前一个比较，如果小于等于前一个数则加至刚好比前一个数大
            fin += before-A[i]+1
            A[i]+= before-A[i]+1
            before=A[i]
        }else{
            before=A[i]
        }
    }
    return fin
}