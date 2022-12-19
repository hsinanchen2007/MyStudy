func fib(n int) int {
    if n == 0 || n == 1{
        return n
    }
    b0 := 0
    b1 := 1
    f := func(){
        tmp := (b0 + b1) % 1000000007
        b0 = b1
        b1 = tmp
    }
    for i := 1; i < n; i++{
        f()
    }
    return b1
}