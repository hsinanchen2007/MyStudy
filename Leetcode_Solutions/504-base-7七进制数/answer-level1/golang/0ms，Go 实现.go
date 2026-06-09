![image.png](https://pic.leetcode-cn.com/66d5b7df0841f93b17d32a773827c78d0b63ca0b8890631bf69095c6a4e81b73-image.png)

```
func Abs(n int) int {
    if n<0 {
        return -n
    }
    return n
}
func convertToBase7(num int) string {
    ans := ""
    for Abs(num)>=7 {
        t := num%7
        num /= 7
        ans = strconv.Itoa(Abs(t)) + ans
    }
    ans = strconv.Itoa(num) + ans
    return ans
}
```