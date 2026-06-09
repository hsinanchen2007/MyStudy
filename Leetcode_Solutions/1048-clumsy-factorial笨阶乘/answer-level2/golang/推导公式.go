推导公式在注释中
```
func clumsy(N int) int {
    // (x+2)(x+1)/x = x+3+2/x => x>2 时 等于x+3
    // 4个数一组，对于第一组 x+3+x-1，y=x+2 (y是本组第一个元素) ==>>  等于2y-2, 
    // 第二组及之后的 -x-3+x-1 = -4
    // 共i组（i=N/4）， sum = 2N-2-4(i-1) = 2(N-2i+1) i>=0
    // ==> sum = 2(N-2i+1) - x , x为N%4的4中情况，
    // 0 : 1 // 反馈第一步中x>2的假设，需要单独考虑N=4的情况，这时候反馈应该是正数。
    // 1 : 1
    // 2 : 2
    // 3 : 6
    
    // 根据 i = N/4 ==> sum = 2N-4i+2 - x = 2N-4(N/4)+2 -x (N > 4)
    // 所以 sum = 2N-N+N%4+2-x = N+2+N%4-x
    // 直接按N%4的4种case计算
    // 0： N+2-1 = N+1
    // 1 : N+3-1 = N+2
    // 2 : N+4-2 = N+2
    // 3 : N+5-6 = N-1
    // 因此简化成
    sum := 0 
    if N > 4 {
        switch N%4 {
            case 0: sum = N+1
            case 1, 2: sum = N+2
            case 3: sum = N-1
        }
    } else {
        switch N {
            case 0: sum = 0
            case 1: sum = 1
            case 2: sum = 2
            case 3: sum = 6
            case 4: sum = 7
        }    
    }
    return sum
}
```
