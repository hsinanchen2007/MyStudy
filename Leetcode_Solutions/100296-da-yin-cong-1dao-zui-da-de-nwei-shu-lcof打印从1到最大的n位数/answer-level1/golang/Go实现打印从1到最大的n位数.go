

```golang
func printNumbers(n int) []int {
    if n<=0{
        return nil
    }
    res := []int{}
    tmp := int(math.Pow(float64(10),float64(n))-1)
    for i:= 1;i<=tmp;i++{
        res = append(res,i)
    }
    return res
}
```