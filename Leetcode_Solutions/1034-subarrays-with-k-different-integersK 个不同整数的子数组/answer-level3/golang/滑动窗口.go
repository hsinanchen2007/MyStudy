转化为至多有`K`个不同整数的子数组的个数 `-` 至多有`K-1`个不同整数的子数组的个数，那么用滑动窗口即解: $sum(A[i:j])\leq K$，则 `ans += j - i + 1`。时间：$O(n)$, 空间：$O(1)$
```go
func atMostK(A []int, K int) int { // A是值传递
    ans, i := 0, 0 
    // cnt := make(map[int]int, 0)
    cnt := [20005]int{}
    for j, v := range A {
        if cnt[v] == 0 {
            K--
        }
        cnt[v]++
        
        for K < 0 {
            cnt[A[i]]-- //
            if cnt[A[i]] == 0 {
                K++
            }   
            i++
        }
        
        ans += j - i + 1
    }
    
    return ans
}

func subarraysWithKDistinct(A []int, K int) int {
    return atMostK(A, K) - atMostK(A, K-1)
}
