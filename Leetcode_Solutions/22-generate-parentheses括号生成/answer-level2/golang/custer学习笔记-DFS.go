# 思考

1. 深度优先搜索，n给定，字符串长度为2*n也固定，字符串数组的长度为2*n，数组中每个元素有两种选择，左括号或右括号，总共有O(2^(2n))，再进行判断是否合法
1. 改进上面的方法，搜索的基础加上剪枝，全部左括号不合法，第一个是右括号不合法等
  - 局部不合法，不再递归，如：第一个右括号
  - 左括号只能放n个，右括号只能放n个，记录左右括号各用多少
  - 时间复杂度O(2^n)

# Python实现

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.list = []
        self._gen(0, 0, n, "")
        return self.list
    
    # left左边的括号已经用了多少个，起始为0，n表示括号总数，result当前产生的括号序列
    def _gen(self, left, right, n, result):
        # 递归终止条件，左右括号都用完了
        if left == n and right == n:
            self.list.append(result)
            return
        if left < n: # 左括号没有用完，多用一个左括号
            self._gen(left+1, right, n, result + "(")
        if left > right and right < n: # 右括号没有用完，右括号总数比左括号少
            self._gen(left, right+1, n, result + ")")
```

# Go实现
学习自https://leetcode-cn.com/problems/generate-parentheses/comments/99823
## 回溯

```go
// Catalan Number
// 回溯算法: Time: O(4^n / sqrt(n)), Space: O(n)
func generateParenthesis(n int) []string {
    if n <= 0 {
        return []string{}
    }
    var result []string
    generate(&result, "", n, n)
    return result
}
// result:保存结果,str:当前组合,left:剩余左括号数量right:剩余右括号数量
func generate(result *[]string, str string, left, right int) {
    if left == 0 && right == 0 { // 剩余左右括号都为0时
        *result = append(*result, str) // 当前组合即为合法排列加入结果
    } else {
        if left > 0 { // 还有剩余的左括号，就添加左括号，左括号并减少1
            generate(result, str+"(", left-1, right)
        }
        if right > left { // 剩余右括号比左括号多，就可以添加右括号
            generate(result, str+")", left, right-1)
        }
    }
}

```

## 动态规划

```go
// 动态规划: Time: O(4^n / n*sqrt(n)), Space: O(4^n / n*sqrt(n))
func generateParenthesisDP(n int) []string {
    if n <= 0 {
        return []string{}
    }
    dp := make([][]string, n+1) // 初始化列表dp
    for i := 0; i < n+1; i++ {
        dp = append(dp, []string{})
    }
    dp[0] = append(dp[0], "") // dp[0]只有一个空串
    for i := 1; i < n+1; i++ {
        for j := 0; j < i; j++ {
            for _, left := range dp[j] { // 从dp[j]和dp[i-j-1]中各拿一个
                for _, right := range dp[i-j-1] { // 合法排列left和right
                    str := "(" + left + ")" + right // left左右加括号得到新的
                    dp[i] = append(dp[i], str)      // 合法排列添加到dp[i]
                }
            }
        }
    }
    return dp[n]
}
```