

```golang
func fib(N int) int {
    if N ==0{
        return 0
    }
    if N ==1{
        return 1
    }
    one := 1
    two := 0
    result :=0
    for i:=2;i<=N;i++{
        result = one+two
         two=one
        one =result
    }
    return result
}
```