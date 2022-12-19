### 解题思路

其实就是前序遍历的思路，最后反转下数组

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
if root == nil {
		return nil
	}
	var stack []*Node
	var res []int

	//把头结点放到列队和返回数据中
	stack = append(stack, root)

	for len(stack) > 0 {
		QLen := len(stack)
		node := stack[len(stack)-1] 
		stack = stack[:QLen-1]     
		if node.Children != nil {
			for k := 0; k < len(node.Children); k++ {
				stack = append(stack, node.Children[k])
			}
		}
		res = append(res, node.Val)
	}

	if res == nil {
		return res
	}

	lp := 0
	rp := len(res) - 1
	for lp < rp { //指针相撞
		res[lp], res[rp] = res[rp], res[lp]
		lp++
		rp--
	}

	return res
}
```