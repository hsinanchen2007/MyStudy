1. 计算高度、最大宽度，期间会遍历该树，同时生成每一层的 `map[层号]节点列表`，空的用nil占位（主要是这一步比较难）
遍历方式：前序遍历，生成的map结构如下：
```
[0xc00000a160]
[<nil> 0xc00000a180]
[<nil> <nil> 0xc00000a1a0 <nil>]
[<nil> <nil> <nil> <nil> <nil> 0xc00000a1e0 <nil> <nil>]
[<nil> <nil> <nil> <nil> <nil> <nil> <nil> <nil> <nil> <nil> <nil> 0xc00000a200 <nil> <nil> <nil> <nil>]
```
2. 然后对每一层的节点列表依次填充进matrix，具体填充算法就是计算每一行的 start 和 gap，可以自己找找规律
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func printTree(root *TreeNode) [][]string {
	dic := make(map[int][]*TreeNode)

	height := walkTreeGetHeight(root, 0, 0, dic)
	width := pow(2, height) - 1

	matrix := initSpace(width, height)

	// 添加第0层节点
	dic[0] = []*TreeNode{root}

	for levelNo := 0; levelNo < height; levelNo++ {
		start := pow(2, height-1-levelNo) - 1
		gap := pow(2, height-levelNo)

		for _, n := range dic[levelNo] {
            // 如果不是空节点，则写入matrix
			if n != nil {
				matrix[levelNo][start] = strconv.Itoa(n.Val)
			}
			start += gap
		}
	}

	return matrix
}

func walkTreeGetHeight(node *TreeNode, depth int, baseIndex int, dic map[int][]*TreeNode) int {
	if node == nil {
		return depth
	}

	// 遍历时，储存每一层数据的指针
	fillChildren(depth+1, node.Left, node.Right, baseIndex, dic)

	// 前序遍历
	lH := walkTreeGetHeight(node.Left, depth+1, baseIndex*2, dic)
	rH := walkTreeGetHeight(node.Right, depth+1, baseIndex*2+1, dic)

	if rH > lH {
		return rH
	}
	return lH
}

func fillChildren(levelNo int, left, right *TreeNode, baseIndex int, dic map[int][]*TreeNode) {
	// 初始化该行容器
    if _, ok := dic[levelNo]; !ok {
		dic[levelNo] = make([]*TreeNode, pow(2, levelNo))
	}

	line := dic[levelNo]
	line[baseIndex*2] = left
	line[baseIndex*2+1] = right
}

// 初始化matrix空间
func initSpace(w, h int) (matrix [][]string) {
	for i := 0; i < h; i++ {
		line := make([]string, w)
		matrix = append(matrix, line)
	}
	return
}

func pow(x, y int) int {
	return int(math.Pow(float64(x), float64(y)))
}

```
