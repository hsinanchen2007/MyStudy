![image.png](https://pic.leetcode-cn.com/5abaf29d93d9e0be172ee886cebcbe64cde5ffa04b380dd62d4abdf819b66a0d-image.png)

遍历每个罗马字符，并判断和前一个罗马字符能否组成特殊组合，如果能组成特殊组合，那么计算累加值

代码：
```
func getCurNum(pre byte, cur byte, x int) (t int) {
    if (cur=='V' && pre=='I') || (cur=='X' && pre=='I') {   // 如果能组成特殊组合，那么计算当前应该累加的值
        t=x-1*2
    } else if (cur=='L' && pre=='X') || (cur=='C' && pre=='X') {
        t=x-10*2
    } else if (cur=='D' && pre=='C') || (cur=='M' && pre=='C') {
        t=x-100*2
    } else {    // 和前一个罗马字符组合起来不是特殊组合，累加值应该是本身
        t=x
    }
    return 
}
func romanToInt(s string) int {
    n := 0
    s = " " + s
    length := strings.Count(s, "") - 1
    for i:=1; i<length; i++ {   // 处理每个罗马字符，并判断和前一个罗马字符能否组成特殊组合
        switch s[i] {
        case 'I':n+=1
        case 'V':n+=getCurNum(s[i-1],s[i],5)
        case 'X':n+=getCurNum(s[i-1],s[i],10)
        case 'L':n+=getCurNum(s[i-1],s[i],50)
        case 'C':n+=getCurNum(s[i-1],s[i],100)
        case 'D':n+=getCurNum(s[i-1],s[i],500)
        case 'M':n+=getCurNum(s[i-1],s[i],1000)
        }
    }
    return n;
}
```