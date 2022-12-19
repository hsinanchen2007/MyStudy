
```go []
func kthGrammar(N int, K int) int {
    if K == 1 {
        return 0
    }
    
    G := kthGrammar(N-1, (K+1)/2 )
    if K % 2 == 1 {
        return G
    }else {
        return 1-G
    }
}
```

关键思路：不断向上寻找目标数的来源，直到N=1，再从开始的0向下推断