## 思路

由于需要我们求出所有可能，因此考虑回溯法。

这里仍然采用我之前反复强调的回溯模板。 定义函数`backtrack(list, temp, excess, lcnt, rcnt, n)`，其中：

- list为我们要返回的数组
- temp 为 中间状态
- excess 表示左边括号比右边括号多的数目
- lcnt表示做括号数
- rcnt 为右括号数

初始化状态为一个左括号。也就是`backtrack(res, temp, 1, 1, 0, n)`。剩下的工作就是填充模板，细节直接看代码即可。

## 代码

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(list, temp, excess, lcnt, rcnt, n):
            if lcnt > n or rcnt > n:
                return
            if len(temp) == 2 * n:
                return list.append(temp)
            if excess > 0:
                temp += ')'
                backtrack(list, temp, excess - 1, lcnt, rcnt + 1, n)
                temp = temp[:-1]
            temp += "("
            backtrack(list, temp, excess + 1, lcnt + 1, rcnt, n)
            temp = temp[:-1]

        res = []
        temp = "("
        backtrack(res, temp, 1, 1, 0, n)
        return res
```

***复杂度分析***

- 时间复杂度：时间复杂度为卡特兰数， 大概是 $O(4^N/\sqrt[2]N)$
- 空间复杂度：由于使用了递归，开辟了额外的栈空间，因此空间复杂度为 $O(N)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)


