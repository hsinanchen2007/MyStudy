```go
func shortestSubarray(A []int, K int) int {
    // 建立sum数组
    var P []int64
    P = append(P, int64(A[0]))
    for i := 0; i < len(A); i++ {
        P = append(P, P[i] + int64(A[i]))
    }
    
    answer := len(A) + 1
    var indexs []int
    
    for i:=0; i < len(P); i++ {
        // 保证递增
        for{
            if len(indexs) == 0 || P[i] > P[indexs[len(indexs) - 1]] {
                break
            }
            indexs = indexs[:len(indexs)-1]
        }
        
        //查找符合条件的最小子数组
        for{
            if len(indexs) == 0 || P[i] < P[indexs[0]] + int64(K) {
                break
            }
            if answer > i - indexs[0] {
                answer = i - indexs[0]
            }
            indexs = indexs[1:]
        }
        
        indexs = append(indexs, i)
    }
    
    if answer == len(A) + 1 {
        return -1
    }
    
    return answer
}
```
