# 解法一 卡特兰数
问组合有多少种，大概率都是 卡特兰数
类似题
[22.括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return nil
	}
	return dfs(1, n)
}

func dfs(start, end int) []*TreeNode {
	var res []*TreeNode
	if start > end {
		res = append(res, nil)
		return res
	}

	for i := start; i <= end; i++ {
		for _, l := range dfs(start, i-1) {
			for _, r := range dfs(i+1, end) {
				cur := &TreeNode{
					Val: i,
				}
				cur.Left = l
				cur.Right = r
				res = append(res, cur)
			}
		}
	}
	return res
}
```

[github](https://github.com/temporaries/leetcode)