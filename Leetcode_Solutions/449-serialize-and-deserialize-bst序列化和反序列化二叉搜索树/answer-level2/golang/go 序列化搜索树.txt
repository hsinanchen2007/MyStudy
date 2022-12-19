1 前序遍历思想 根->左->右 to string
2 递归插入 先拿出根  搜索树的思想  左树比根小 依次插入到左树， 右比根大  依次插入到右树
```
type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	data := make([]string, 0)
	helperSerialize(root, &data)
	return strings.Join(data, ",")
}

func helperSerialize(root *TreeNode, data *[]string) {
	if root == nil {
		return
	}
	*data = append(*data, strconv.Itoa(root.Val))
	helperSerialize(root.Left, data)
	helperSerialize(root.Right, data)
}

func helperDeserialize(a *TreeNode, b *TreeNode) {
	if b.Val < a.Val {
		if a.Left != nil {
			helperDeserialize(a.Left, b)
		} else {
			a.Left = b
		}
	}
	if b.Val > a.Val {
		if a.Right != nil {
			helperDeserialize(a.Right, b)
		} else {
			a.Right = b
		}
	}
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if len(data) == 0 {
		return nil
	}
	nums := make([]int, 0)
	for _, v := range strings.Split(data, ",") {
		ints, _ := strconv.Atoi(v)
		nums = append(nums, ints)
	}
	node := TreeNode{
		Val: nums[0],
	}
	for i := 0; i < len(nums); i++ {
		helperDeserialize(&node, &TreeNode{Val: nums[i]})
	}
	return &node
}
```
