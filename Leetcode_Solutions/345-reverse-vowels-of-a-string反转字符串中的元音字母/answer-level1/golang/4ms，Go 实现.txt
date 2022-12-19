
![image.png](https://pic.leetcode-cn.com/e12350372d81c4df0526bd21c743270031729082c21b2ddcc532ecac9a6d7d56-image.png)

```
func isValid(c rune) bool {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
           c=='A' || c=='E' || c=='I' || c=='O' || c=='U'
}

func reverseVowels(s string) string {
    t := []rune(s)
    for i,j := 0,len(t)-1; i<j; {
        for ; i<j && !isValid(t[i]); i++ { // 从前往后找到第一个元音字母
        }
        for ; i<j && !isValid(t[j]); j-- { // 从后往前找到第一个元音字母
        }
        if i<j {
            t[i],t[j] = t[j],t[i]       // 交换位置
            i++
            j--
        }
    }
    return string(t)
}
```