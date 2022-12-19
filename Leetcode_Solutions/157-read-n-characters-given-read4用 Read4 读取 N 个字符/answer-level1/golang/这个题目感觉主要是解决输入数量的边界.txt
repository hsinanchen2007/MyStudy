
![image.png](https://pic.leetcode-cn.com/e6e87cd0e70ea7b6b29bbaac2615a7123c2930393ba9361587ea9118d6021b62-image.png)
成绩不一定最好，主要是没有人提交Go。
```
var solution = func(read4 func([]byte) int) func([]byte, int) int {
    // implement read below.
    return func(buf []byte, n int) int {
        res := make([]byte, 4)
        sum := 0
        for {
            num := read4(res)
            if num > 0 {    
                for i:=0; i<num; i++ {   
                    if sum >= n {
                        break
                    }
                    buf[sum] = res[i]
                    sum++
                }
            }
            if sum >= n || num == 0 {
                break
            }
        }
        return sum
    }
}

```
一定要处理好输出预期是n字符。我在read4的时候，最后一次可能会超出，这块多余的去掉不返回就可以了。
buf认为是长度足够的，持续往里面copy读到的结果即可。