## 结果

![image.png](https://pic.leetcode-cn.com/cfdbd7a9239999955ce47ca79d93c155dd9c936800aebd7eb971f5a969e52a29-image.png)


### 解题思路

经典的二叉树层次遍历问题，使用队列来保存每一层的节点
- 开始时队列里只有根节点，进入循环
- 当队列节点不为空时，从队头开始取出队列中所有节点，这时候所有节点就是当前层的所有节点
- 对所有取出的节点，将他们的左右子节点（如果存在）依次加入队列中，回到上一步
- 当队列为空，说明遍历结束，程序退出

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
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
	var result = make([][]int, 0)
	var queue = list.New()
	queue.PushBack(root)

	for queue.Len() != 0 {
		var level = make([]int, 0)
		tmp := list.New()
		for queue.Len() > 0 {
			node := queue.Remove(queue.Front()).(*TreeNode)
			level = append(level, node.Val)
			tmp.PushBack(node)
		}
		result = append(result, level)
		for tmp.Len() > 0 {
			node := tmp.Remove(tmp.Front()).(*TreeNode)
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
		}

	}

	return result
}

```