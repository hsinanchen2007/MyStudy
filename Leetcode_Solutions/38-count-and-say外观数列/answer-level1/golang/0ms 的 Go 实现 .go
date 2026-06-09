
![image.png](https://pic.leetcode-cn.com/dd30c888ae118810ab4591e8e3421bb054813f45eef587298f38256f5af2c026-image.png)

没什么好说的，模拟生成下一个字符串

代码
```
func countAndSay(n int) string {
    s := "1"
    for n>1 {   // 循环生成下一个字符串
        curs := ""
        curc := s[0]
        cnt := 0
        for i:=0; i<len(s); i++ { // 遍历当前字符串，根据规则生成下一个字符串
            if curc != s[i] { // 遇到不相等的数字
                // 累加新字符串
                curs += strconv.Itoa(cnt) + string(curc)
                // 计数重置
                curc = s[i] // 换新数字
                cnt = 1
            } else { // 遇到相等的数字，增加计数
                cnt++
            }
        }
        // 累加新字符串
        curs += strconv.Itoa(cnt) + string(curc)
        
        // 生成的下一个字符串
        s = curs
        n--
    }
    return s
}
```