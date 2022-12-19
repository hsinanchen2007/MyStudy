```
func climbStairs(n int) int {
    
    // 用map结构作为缓存池，key是n，value是结果
    cache := make(map[int]int, n)
    
    return climbStairsWithCache(n, cache)
}

func climbStairsWithCache(n int, cache map[int]int) int {
    
    if n == 1 { // 只有一层阶梯，则肯定只有一种走法
        return 1
    } else if n == 2 { // 只有二层阶梯，则有两种走法，走两次一层或者走一次两层
        return 2
    } else if v, ok := cache[n]; ok { // 先从缓存池中获取，如果之前计算过，则直接返回结果
        return v
    }
    
    // 假设要到达第N层，只有两种走法：从N-1层上来；从N-2层上来。这两种走法之和，即为到达第N层的走法总数
    v := climbStairsWithCache(n - 1, cache) + climbStairsWithCache(n - 2, cache)
    // 缓存结果
    cache[n] = v
    
    return v
}
```
