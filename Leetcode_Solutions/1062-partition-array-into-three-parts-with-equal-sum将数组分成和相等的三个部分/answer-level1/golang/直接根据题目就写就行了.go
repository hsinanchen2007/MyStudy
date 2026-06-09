```
func canThreePartsEqualSum(A []int) bool {
   sum:=0
    for i:=0;i<len(A);i++{
        sum+=A[i]
    }
    if sum%3 !=0{
        return false
    }
    tag:=sum/3
    num:=0
    ans:=0
    for j:=0;j<len(A);j++{
        ans+=A[j]
        if ans==tag{
            ans=0
            num++
        }
    }
    if num<3{
        return false
    }
    return true
}
```
