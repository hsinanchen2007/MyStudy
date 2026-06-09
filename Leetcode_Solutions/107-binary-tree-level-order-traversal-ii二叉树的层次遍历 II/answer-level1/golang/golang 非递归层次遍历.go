```
func levelOrderBottom(root *TreeNode) [][]int {
	// 从上到一层一层遍历每次遍历一个节点的时候记录节点值和它左右的孩子


	res := make([][]int,0)
	if root == nil {									// 为nil直接返回
		return res										
	}
	nodes := make([]*TreeNode,0)
	nodes = append(nodes,root)
	for len(nodes)!=0 {									// nodes不为0就一直循环
		tmp := []int{}									// 记录这层的数值
		count := len(nodes)								// 统计这一层的节点数
		for i :=0;i<count;i++ { 						// 循环次数等于每一层的节点数，每次都取第一个node，因为下面会将第一个node删除
			tmp = append(tmp,nodes[0].Val)				// 记录节点值
			if nodes[0].Left != nil {					// 如果左子树不为空，将左子树添加nodes
				nodes = append(nodes,nodes[0].Left)
			}
			if nodes[0].Right != nil {					// 如果右子树不为空，将右子树添加到nodes
				nodes = append(nodes,nodes[0].Right)
			}
			nodes = nodes[1:]							// 将第一个node删除
		}
		res = append(res,tmp)							// 记录每一层的值
	}
	i,j := 0,len(res)-1
	for i<j  {											// 反转每一层的值
		tmp := res[i]
		res[i] = res[j]
		res[j] = tmp
		i ++
		j --
	}
	return res											// 返回结果
}


```