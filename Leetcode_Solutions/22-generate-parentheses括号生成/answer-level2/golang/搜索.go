### 解题思路
搜索算法题，首先确定搜索条件和搜索空间，然后制定搜索策略，搜索策略指搜索顺序和搜索范围。 n 对括号，所以合法字符串的长度应为 2n，每一个左括号都必须匹配一个右括号，所以左右括号的数量都为 n,最重要的一点，生成右括号的条件是右括号的数量要小于左括号的数量，否则后面的左括号是无法匹配前面的左括号的。

### 代码

```golang
func generateParenthesis(n int) []string {
    var backtrack func(left int, right int, temp string, n int) //声明函数
    ans := make([]string,0)   //保存答案
    backtrack = func(left int, right int, temp string, n int){
        if right == n && left == n && len(temp) == 2*n { //判断字符串是否合法
            ans = append(ans,temp)
        }
        if left < n {      //生成左括号
            backtrack(left+1, right, temp+"(",n)
        }
        if right < left && right < n{   //生成右括号
            backtrack(left, right+1, temp+")", n)
        }

    }
    backtrack(0, 0, "", n)
    return ans
}

```