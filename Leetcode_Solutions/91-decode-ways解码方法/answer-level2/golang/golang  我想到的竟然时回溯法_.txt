```go
/**
1. 求总数 让我想到 回溯法,遍历解空间
2. 当 s 的长度为0 时 代表搜索完毕 添加一种编码方法
3. 当 s[0] 是 0时 直接返回 此种情况无法编码
4. 分两种情况进行回溯
    1) 仅拿一个字符编码时
    2) 当 拿两个字符编码 组成的数字在 1-26之间时
*/

func numDecodings(s string) int {
    sum := 0
    dfs(&sum,s)
    return sum
}

func dfs(n *int,s string){
    if len(s) == 0 {
        *n ++
        return 
    }
    if (s[0]-'0') == 0{
        return 
    }
    dfs(n,s[1:])
    if len(s) > 1{
        m := (s[0]-'0') * 10 + (s[1] - '0')
        if m >= 1 && m <= 26{
            dfs(n,s[2:])
        }       
    }
}
```