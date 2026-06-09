![image.png](https://pic.leetcode-cn.com/2332cc128c1ffec03f99adef81fb765bbe3665f8eddc8aa1ea0b30964eca7fc0-image.png)

```
func countPrimes(n int) int {      // 筛法求质数
    a := make([]bool, n)
    cnt := 0
    for i:=2; i<n; i++ {
        if a[i] {                  // 这是数设置过 true 了，说明之前存在因子，不是质数
            continue
        }
        for j:=i+i; j<n; j+=i {    // 所有 i 的倍数都置 true，因为 i 是他们的因子，肯定不是质数了
            a[j] = true
        }
        cnt++
    }
    return cnt
}
```