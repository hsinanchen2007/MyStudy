

```golang
func cuttingRope(n int) int {
    if n==2{
        return 1
    }
    if n == 3{
        return 2
    }
    timesOf3 := n/3
    if n-timesOf3*3==1{
        timesOf3--
    }
    timesOf2 := (n-timesOf3*3)/2
    result := int(math.Pow(float64(3),float64(timesOf3))*math.Pow(float64(2),float64(timesOf2)))
    return result
}
```