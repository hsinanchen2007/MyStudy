
![image.png](https://pic.leetcode-cn.com/d5918e22afdc20650609a211874b52928e6e7dde4e38cbe9303f95507dc91e72-image.png)

```
func countSegments(s string) int {
    ans := strings.Fields(s)
    return len(ans)
}
```