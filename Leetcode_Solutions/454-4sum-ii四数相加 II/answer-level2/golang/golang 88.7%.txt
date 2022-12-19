```
/*将C+D的每一种可能放入查找表（map）  这样我们只需要寻找这个表里面有没有-A-B就行了     有的话则A+B+C+D=0，然后统计一下个数*/

func fourSumCount(A []int, B []int, C []int, D []int) int {
    result:=0
    CD_sums:=make(map[int]int)
    for i:=0;i<len(C);i++{
        for j:=0;j<len(D);j++{
            CD_sums[C[i]+D[j]]++
        }
    }
    for i:=0;i<len(A);i++{
        for j:=0;j<len(B);j++{
            result+=CD_sums[-A[i]-B[j]]
            
        }
    }
    return result;
}
```
