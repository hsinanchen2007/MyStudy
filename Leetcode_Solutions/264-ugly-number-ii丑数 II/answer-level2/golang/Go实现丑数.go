
```golang
func nthUglyNumber(n int) int {
    res := []int{}
    res = append(res,1)
    i2,i3,i5:= 0,0,0
    index := 1
    for index<n{
        res = append(res,int(math.Min(float64(2*res[i2]),math.Min(float64(3*res[i3]),float64(5*res[i5])))))
        if res[index]==2*res[i2]{
            i2++
        }
         if res[index]==3*res[i3]{
            i3++
        }
         if res[index]==5*res[i5]{
            i5++
        }
        index++
    }
    return res[index-1]
}
```