### 解题思路

dfs

### 代码

```golang

func smallestFromLeaf(root *TreeNode) string {

	if root == nil {
		return ""
	}

	var curList []byte
	minStr := ""
	dfs(root, curList, &minStr)
	return minStr
}

// curList 表示当前节点之前的父节点的列表，不包含当前节点；且 cur不为nil
func dfs(cur *TreeNode, curList []byte, minStr *string) {

	// 因为 curList 进入的时候不包含当前节点，所以这里要追加
	// curList = append(curList)
	curList = append([]byte{byte('a' + cur.Val)}, curList...)
	if cur.Left == nil && cur.Right == nil {

		if *minStr == "" {
			*minStr = string(curList)
		} else if string(curList) < *minStr {
			*minStr = string(curList)
		}
		return
	}

	if cur.Left != nil { //如果没有这个判断，那么进入函数的开始地方 就要 判断非空
		dfs(cur.Left, curList, minStr)
	}

	if cur.Right != nil { //如果没有这个判断，那么进入函数的开始地方 就要 判断非空
		dfs(cur.Right, curList, minStr)
	}
	return
}

```