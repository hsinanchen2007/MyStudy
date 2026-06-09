# 暴力 dfs
1. 计算时，如 [1.two-sum](https://leetcode-cn.com/problems/two-sum/) 的暴力法

```golang
var res int
var s int

func pathSum(root *TreeNode, sum int) int {
	res = 0
	s = sum
	fall(root)
	return res
}

func fall(root *TreeNode) {
	if root == nil {
		return
	}
	fall(root.Left)
	fall(root.Right)
	dfs(root, 0)
}

func dfs(root *TreeNode, cur int) {
	if root != nil {
		cur += root.Val
		if s == cur {
			res++

		}
		dfs(root.Left, cur)
		dfs(root.Right, cur)
	}
}
```

# `前缀和（哈希表）` dfs
1. 计算时，如 [1.two-sum](https://leetcode-cn.com/problems/two-sum/) 的哈希表

```golang
var s int
var prefixSum map[int]int

func pathSum(root *TreeNode, sum int) int {
	s = sum
	prefixSum = map[int]int{}
	prefixSum[0] = 1
	return dfs(root, 0)
}

func dfs(root *TreeNode, cur int) int {
	if root == nil {
		return 0
	}
	cur += root.Val
	res := prefixSum[cur-s] //负数索引忽略。刚好为0，或者刚好为前缀  则+1
	prefixSum[cur]++        //加入前缀
	res += dfs(root.Left, cur) + dfs(root.Right, cur)
	prefixSum[cur]-- //取消前缀
	return res
}
```

#
[`Go版本 Github`](https://github.com/temporaries/leetcode)

