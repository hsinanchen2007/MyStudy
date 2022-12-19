```
func selfDividingNumbers(left int, right int) []int {
    var res []int
    for i:=left; i<=right;i++{
        var temp = i
        var temp2 int
        for temp != 0{
            temp2 = temp % 10
            if temp2 == 0 || i % temp2 !=0{
                break
            }else{
                temp /= 10
            }
        }
        if temp == 0{
            res = append(res,i)
        }
    }
    return res
    
}
```