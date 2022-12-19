

```golang
func myPow(x float64, n int) float64 {
    if n == 1{
        return x
    }
    if n == 0{
        return 1
    }
    if n<0{
        x=1/x
        n=-n
    }
    tmp := myPow(x,n>>1)
    if n&1==0{
        return tmp*tmp
    }
        return x*tmp*tmp
}
```