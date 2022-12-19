
![image.png](https://pic.leetcode-cn.com/f5598647e34cadefa8a055654c5d34dcb0b1248c76dad7e7abc771acf2eeac06-image.png)

```
func toLowerCase(str string) string {
    ans := ""
    for _,x := range str {
        if 'A' <= x && x<= 'Z' {
            x += 32
        }
        ans += string(x)
    }
    return ans
}
```