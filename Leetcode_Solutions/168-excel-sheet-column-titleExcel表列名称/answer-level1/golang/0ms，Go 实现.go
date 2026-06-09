
![image.png](https://pic.leetcode-cn.com/40f1da6439566f9526eace9be42796bd956c721541c88fbdc34f7038f035971d-image.png)

```
func convertToTitle(n int) string { // 相当于一个26进制转换
    hash := [26]string{}
    for i:=0; i<26; i++ {   // 数字和字母的对应表
        hash[i] = string('A' + i)
    }
    ans := ""
    for n!=0 {
        t := (n-1)%26
        ans = hash[t] + ans
        n = (n-1)/26
    }
    return ans
}
```