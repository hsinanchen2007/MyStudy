
![image.png](https://pic.leetcode-cn.com/046621db04a430e7efc566c5ea03641638e58ee235d74f2ce35c7394f787b82d-image.png)

如果是负数，先转换成补码形式，比如：-1 + 4294967296 = 4294967295 = 0xffffffff

然后再按位提取十六进制字符，累加成结果字符串。

```
func toHex(num int) string {
    if num < 0 {    // 如果是负数，转换成补码形式，比如：-1 + 4294967296 = 4294967295 = 0xffffffff
        num += 4294967296
    }
    ans := []rune{}
    hash := [26]rune{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}
    for {           // 迭代提取每个位上的十六进制字符
        t := num%16
        num /= 16
        ans = append([]rune{hash[t]}, ans...)
        if num == 0 {
            break
        }
    }
    return string(ans)
}
```