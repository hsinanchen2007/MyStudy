用字符串每个字符的累乘结果唯一标识这个字符串（反正也不要求顺序）

```
func getSum(s string) int {   // 判断两个字符串是否为字母异位词
    sum := 1
    for i:=0; i<len(s); i++ {
        sum *= int(s[i])
    }
    return sum
}

func findAnagrams(s string, p string) []int {
    slen := len(s)
    plen := len(p)
    ans := []int{}
    psum := 1
    for i:=0; i<len(p); i++ {           // 计算 p 的字符累乘结果
        psum *= int(p[i])
    }
    for i:=0; i<=slen-plen; i++ {       // 统计每个索引开始的字符串是否和 p 是字母异位词
        if getSum(s[i:i+plen]) == psum {
            ans = append(ans, i)
        }
    }
    return ans
}
```