### 解题思路
费马平方数定理

### 代码

```golang
func judgeSquareSum(c int) bool {
    for i := 2; i * i <= c; i++ {
        cnt := 0
        if c % i == 0 {
            for c % i == 0 {
                cnt++
                c /= i
            }
            if i % 4 == 3 && cnt % 2 != 0 {
                return false
            }
        }
    }
    return c % 4 != 3
}
```