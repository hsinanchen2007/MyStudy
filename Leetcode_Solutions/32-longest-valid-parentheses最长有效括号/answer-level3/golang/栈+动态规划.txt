## 方法一：

二维数组的动态规划：O(n^2)

- mat[i][j]表示s[i:j+1]为有效括号
- 如何求mat[i][j]?
- 先借用栈获取k，使得s[k:j+1]为以s[j]为结尾的最短有效括号,mat[k][j]=true
- 如果mat[i][k-1]=true,则mat[i][j]=true

```
func longestValidParentheses(s string) int {
    if s==""||len(s)<2{
        return 0
    }
    n := len(s)
    mat := make([][]bool,n)
    for i:=0;i<n;i++ {
        mat[i] = make([]bool,n)
    }
    ans := 0
    
    for j:=1;j<n;j++{
        if s[j] != ')' {
            continue
        }
        cnt := 1
        k:=j-1
        for ;k>=0;k--{
            if s[k] == '('{
                cnt--
                if cnt == 0 {
                    mat[k][j] = true
                    ans = max(ans,j-k+1)
                    break
                }
            }
            if s[k] == ')'{
                cnt++
            }
        }
        k--
        for i:=k-1;i>=0;i-=2{
            if mat[i][k] {
                mat[i][j]=true
                ans = max(ans,j-i+1)
            }
        }
    }
    return ans
}

func max(i ,j int) int {
    if i > j {
        return i
    }
    return j
}
```


## 方法二：

- 栈+动态规划:时间复杂度O(n)
- dp[i]表示已s[i]结尾的最长有效括号

```
func longestValidParentheses(s string) int {
    if s==""||len(s)<2{
        return 0
    }
    n := len(s)
    ans:=0
    dp := make([]int,n)
    stack := make([]int,0)
    for i:=0;i<n;i++{
        if s[i]==')' {
            if len(stack) != 0 {
                idx := stack[len(stack)-1]
                stack = stack[:len(stack)-1]
                dp[i]=i-idx+1
                if idx -1 >= 0 {
                    dp[i] += dp[idx-1]
                }
                ans = max(ans,dp[i])
            }
        }
        if s[i] == '(' {
            stack = append(stack,i)
        }
    }
    return ans
}

func max(i ,j int) int {
    if i > j {
        return i
    }
    return j
}
```
