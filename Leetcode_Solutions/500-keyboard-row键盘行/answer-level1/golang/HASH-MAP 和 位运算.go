### HASH 和 位运算
hash map 加快检索
位运算值排除

![微信截图_20200110160651.png](https://pic.leetcode-cn.com/863310c611d3bbe9b1facbdf77f7f30d81407df1333c0c6d141001b5c1b481a4-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200110160651.png)


### 代码

```golang
func findWords(words []string) []string {
    m := map[rune]int {}
    for _,v := range "QWERTYUIOP" {
        m[v] = 1<<1
    }
    for _,v := range "ASDFGHJKL" {
        m[v] = 1<<2
    }
    for _,v := range "ZXCVBNM" {
         m[v] = 1<<3
    }

    resW := []string{}

    for _,ww := range words {
        w := strings.ToUpper(ww)
        res := 0
        for i,wr := range w {
            vvvv := m[wr]
            if i == 0 {
                res = vvvv
            } else{
                //位运算值判断是否跨行
                res = res & vvvv
            }

        }
        if res > 0 {
            resW = append(resW,ww)
        }
    }
    return resW
}


```