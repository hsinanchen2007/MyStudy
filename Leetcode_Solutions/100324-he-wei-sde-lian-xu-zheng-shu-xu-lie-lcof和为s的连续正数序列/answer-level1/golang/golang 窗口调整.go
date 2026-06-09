### 解题思路
不断进行窗口调整，并将结果存入二维数组

### 代码

```golang
func findContinuousSequence(target int) [][]int {
    res := make([][]int, 0)
    left := 1
    ans := 0
    for right := 1; right < target/2 + 2; right++ {
        ans += right
        //动态调整
        for ans > target {
            ans -= left
            left++
        }
        if ans == target {
            tmp := make([]int, 0)
            for i := left; i <= right; i++ {
                tmp = append(tmp, i)
            }
            res = append(res, tmp)
        }
    }
    return res
}
```