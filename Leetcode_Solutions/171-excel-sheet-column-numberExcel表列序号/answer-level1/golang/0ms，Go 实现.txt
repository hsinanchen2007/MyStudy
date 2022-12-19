![image.png](https://pic.leetcode-cn.com/e55105d6b1195baaeac63cccb4f04f3f5b2e38e996d5390b61567b026fe2c6c3-image.png)

代码
```
func titleToNumber(s string) int {
    ans := 0
    for _,x := range s {
        t := int(x - 'A') + 1
        ans = ans*26 + t
    }
    return ans
}
```