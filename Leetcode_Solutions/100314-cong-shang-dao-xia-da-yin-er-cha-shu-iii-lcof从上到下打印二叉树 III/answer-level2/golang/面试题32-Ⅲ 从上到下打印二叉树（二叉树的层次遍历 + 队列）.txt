### 解题思路
日常学习[@jyd](/u/jyd/)大佬
[大佬详细讲解传送门](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/solution/mian-shi-ti-32-iii-cong-shang-dao-xia-da-yin-er--3/)

### 知识点：二叉树的层次遍历 + 队列

### 代码
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
// 二叉树的层次遍历 + 队列
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	res := make([][]int, 0) // 结果数组
	queue := make([]*TreeNode, 0)		// 用一维切片模拟队列
	queue = append(queue, root)
	// 当队列不为空时，循环继续
	for len(queue) != 0 {
		tmp := make([]int, 0)
		queueLen := len(queue)
		for _, node := range queue {
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		
		// res 的偶数层逆序，奇数层的下一层为偶数层
		if len(res) % 2 != 0 {
			tmp = reverse(tmp)
		}
		res = append(res, tmp)

		// 新一层的节点队列
		queue = queue[queueLen:]	// 左闭右开
	}
	return res
}

// 反转切片
func reverse(tmp []int) []int {
	for i, j := 0, len(tmp)-1; i < j; i, j = i+1, j-1 {
		tmp[i], tmp[j] = tmp[j], tmp[i]
	}
	return tmp
}
```