
![image.png](https://pic.leetcode-cn.com/6def171d16b329bb921a94c7ffceeb685821a076a1993902dd18b53fd3ff6f15-image.png)


写一个递归，每次可以有入栈和出栈操作，遍历所有可能性。

```
var ans []string

func dfs(n int, cur string, stack []byte) {    // 当前字符串组合 cur，当前前括号栈（只存储前括号）stack
    if len(cur)>=n*2 {
        if len(stack)==0 {
            ans = append(ans, cur)
        } 
        return 
    }
    // 两种操作：入栈和出栈
    if len(stack) <= n && len(cur) <=n*2 {   // 入栈，代表当前字符串 cur 累加一个前括号；前括号栈只存储前括号，大小不能超过3
        dfs(n, cur+"(", append(stack, '('))
    }
    if len(stack) > 0 {                     // 出栈，代表当前字符串 cur 累加一个后括号；前括号栈此时不能为空
        dfs(n, cur+")", stack[:len(stack)-1])
    }
}

func generateParenthesis(n int) []string {
    ans = []string{}
    dfs(n, "", []byte{})
    return ans
}
```