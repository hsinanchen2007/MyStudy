### 解题思路
- 序列化时
	- 广度优先搜索  用数组表示二叉树，当节点不为空时才将左右子树push进队列，也就是 数组是成对出现的，最后将数组转化为string
- 反序列化时
	-  先判断空
	- 广度优先搜索 两个堆栈，一个表示元素的数组，一个表示待处理的节点栈Q 再建立第一个root，root入栈，处理完的元素出栈
	- Q pop ，元素pop出两个栈元素，因为是前序遍历，所以两个元素分别表示左右子树

### 代码

```golang

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// 广度优先搜索  用数组表示二叉树，当节点不为空时才将左右子树push进队列，也就是 数组是成对出现的
// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {

	if root == nil {
		return ""
	}
	var res strings.Builder
	var stack []*TreeNode
	stack = append(stack, root)

	for len(stack) != 0 {
		//pop
		Node := stack[0]
		stack = stack[1:]
		// 左右子树入队
		if Node == nil {
			res.WriteString("# ")

		} else { // 当前节点不为空时才入队列
			res.WriteString(strconv.Itoa(Node.Val) + " ")
			// 当节点不为空时将左右子树入队
			stack = append(stack, Node.Left)
			stack = append(stack, Node.Right)
		}
	}
	return res.String()
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if len(data) == 0 {
		return nil
	}

	values := strings.Split(data, " ")
	// pop 第一个元素建立root
	v, _ := strconv.Atoi(values[0])
	values = values[1:]

	root := &TreeNode{Val: v}

	var Q []*TreeNode
	Q = append(Q, root)
	for len(Q) != 0 {
		// pop  tree node
		p := Q[0]
		Q = Q[1:]

		// 第一个元素为左子树
		if values[0] != "#" {
			l, _ := strconv.Atoi(values[0])
			p.Left = &TreeNode{Val: l}
			Q = append(Q, p.Left)
		}
		// 为空的情况可以省略，模式指针就是nil

		// 第二个元素为右子树
		if values[1] != "#" {
			r, _ := strconv.Atoi(values[1])
			p.Right = &TreeNode{Val: r}
			Q = append(Q, p.Right)
		}
		// pop出两个元素
		values = values[2:]
	}
	return root
}

```