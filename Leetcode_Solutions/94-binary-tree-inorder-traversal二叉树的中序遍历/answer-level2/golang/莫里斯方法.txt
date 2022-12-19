
### 算法描述

- 时间：100%
- 空间：99.56%

#### 寻找前驱节点

- 从当前节点的左孩子的右孩子一直往右孩子找，找到最后一个右孩子即是当前节点的前驱节点
#### 遍历过程
- 如果当前节点的左孩子为空，那么直接输出当前节点，并且将右节点作为当前节点
- 如果当前节点的左孩子不空，则寻找当前节点的前驱节点
  - 如果前驱节点的右孩子为空，那么设置为当前节点，并且将当前节点的左孩子作为当前节点
  - 如果前驱节点的右孩子不空，那么肯定就是当前节点了，直接输出当前节点，并且将右孩子作为当前节点

#### 代码：

```
func inorderTraversal(root *TreeNode) (rst []int) {
	for root != nil {
		if root.Left == nil {
			rst = append(rst, root.Val)
			root = root.Right
		} else {
			prev := getPredecessor(root)
			if prev.Right == nil {
				prev.Right = root
				root = root.Left
			} else if prev.Right == root {
				prev.Right = nil
				rst = append(rst, root.Val)
				root = root.Right
			}
		}
	}

	return
}

func getPredecessor(root *TreeNode) *TreeNode {
	var prev = root
	if prev.Left != nil {
		prev = prev.Left
		for prev.Right != nil && prev.Right != root {
			prev = prev.Right
		}
	}
	return prev
}
```
