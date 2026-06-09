
![image.png](https://pic.leetcode-cn.com/4f2918dd5ce8aa19edbed2bdbaa18566b6e2a418e8a58d9f196aaff3025792ad-image.png)


用 t 中所有字符元素的和减去 s 中所有元素的和，就是多出来的那个字符。

```
func findTheDifference(s string, t string) byte {
    ssum,tsum := 0,0
    for _,x := range s {
        ssum += int(x)
    }
    for _,x := range t {
        tsum += int(x)
    }
    return byte(tsum-ssum)
}
```