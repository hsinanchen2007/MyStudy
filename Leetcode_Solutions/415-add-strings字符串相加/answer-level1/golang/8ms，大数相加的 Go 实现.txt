
![image.png](https://pic.leetcode-cn.com/e2de4849454f0a355b93e7eeca256c1b43b88598db3432311720b20638ec72a5-image.png)

大数相加，每次处理一位

```
func addStrings(num1 string, num2 string) string {  // 大数加法
    ans := ""
    add := 0    // 进位
    cur := 0    // 当前位
    i,j := len(num1)-1,len(num2)-1
    for ;i>=0 || j>=0 || add!=0; {
        if i<0 && j>=0 {    // 计算当前位的值
            cur = int(num2[j]-'0') + add 
        } else if j<0 && i>=0 {
            cur = int(num1[i]-'0') + add 
        } else if i<0 && j<0 {
            cur = add
        } else {
            cur = int(num1[i]-'0' + num2[j]-'0') + add 
        }
        if cur > 9 {        // 获取当前位和进位
            add = cur/10
            cur -= 10
        } else {
            add = 0
        }
        ans = string(cur+'0') + ans // 累加结果
        i--
        j--
    }
    return ans
}
```