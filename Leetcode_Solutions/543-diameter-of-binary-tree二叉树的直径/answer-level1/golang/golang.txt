golang

github: https://github.com/Crownt/leetcode

解法一：
```go
// 当前节点左子树的深度与右子树的深度之和即为以当前节点为根的二叉树的最长路径
// 两次递归中序遍历嵌套，一次为求以每个节点为根的数的深度，一次为求以每个节点为根的最长路径
// 时间复杂度：O(n^2)  空间复杂度：O(h^2)  h为树的高度，每一层递归都需要分配栈空间，每一层中分配的空间为常数
 
var max_path int  // 通过全局变量记录最长路径

func diameterOfBinaryTree(root *TreeNode) int {
	max_path = 0  // 刷新全局变量

	getDiameterOfBinaryTree(root)
	return max_path		
}

// 递归中序遍历每个节点，计算以该节点为根节点的最长路径，比较所有节点的最长路径获取整棵树的最长路径
func getDiameterOfBinaryTree(root *TreeNode) {
	if root==nil {
		return
	}

    // 当前节点左子树的深度与右子树的深度之和即为以当前节点为根的二叉树的最长路径
	path := getDepthOfBinaryTree(root.Left) + getDepthOfBinaryTree(root.Right)
	if path>max_path {
		max_path = path
	}

	getDiameterOfBinaryTree(root.Left)
	getDiameterOfBinaryTree(root.Right)
}

// 计算以当前节点为根节点的树的深度
func getDepthOfBinaryTree(root *TreeNode) int {
	if root==nil {
		return 0
	}

	return int(math.Max(float64(getDepthOfBinaryTree(root.Left)), 
	float64(getDepthOfBinaryTree(root.Right)))) + 1
}
```

解法二：

```go
// 当前节点左子树的深度与右子树的深度之和即为以当前节点为根的二叉树的最长路径
// 比较Solution_1，考虑在求树的深度的同时将最长路径一并求得，则只需一次递归中序遍历即可
// 时间复杂度：O(n)  空间复杂度：O(h)  h为树的高度，每一层递归都需要分配栈空间，每一层中分配的空间为常数
 
var max_path_2 int  // 通过全局变量记录最长路径

func diameterOfBinaryTree(root *TreeNode) int {
	max_path_2 = 0  // 刷新全局变量

	getDepthAndDiameterOfBinaryTree(root)
	return max_path_2		
}

// 计算以当前节点为根节点的树的深度以及最长路径
func getDepthAndDiameterOfBinaryTree(root *TreeNode) int {
	if root==nil {
		return 0
	}

	depth_left := getDepthAndDiameterOfBinaryTree(root.Left)
	depth_right:= getDepthAndDiameterOfBinaryTree(root.Right)

	// 当前节点左子树的深度与右子树的深度之和即为以当前节点为根的二叉树的最长路径path
	path := depth_left + depth_right
	if path>max_path_2 {
		max_path_2 = path
	}

	return int(math.Max(float64(depth_left), float64(depth_right))) + 1
}
```

