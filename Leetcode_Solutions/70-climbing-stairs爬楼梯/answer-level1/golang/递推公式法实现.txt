
使用递推公式实现:

![递推公式](https://pic.leetcode-cn.com/1d61fb1af4b467bcf688eec3e51a9f23eb84fdc992d20565031f510322cd4a14-file_1571111486090)

**参考:** https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/

**代码:**

```go
import (
    "math"
)
func climbStairs(n int) int {
    s5:=math.Sqrt(5);
    return int(math.Round((math.Pow((1+s5)/2 , float64(n+1)) -  math.Pow((1-s5)/2, float64(n+1))) /s5));
}
```