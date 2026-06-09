### 解题思路
主要是二叉搜索树的插入，与遍历

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

type Codec struct {
    
}

func Constructor() Codec {
	return Codec{}
}


// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	var data string
	pre_order(root, &data)
	return data
}


// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	data_value := strings.Split(data, "#")
	var d []int

	for _, v := range data_value {
		if v == "" {
			continue
		}
		ii:= func() int {
			d, _ := strconv.Atoi(v)
			return d
		}()
		d= append(d, ii)
	}
	if len(d) == 0 {
		return nil
	}
	node := TreeNode{Val: d[0]}
	for i := 0; i < len(d); i++ {
		BST_insert(&node, &TreeNode{Val: d[i]})
	}

	return &node
}
func pre_order(node *TreeNode, data *string) {
	if node == nil {
		return
	}

	*data = *data + "#" + strconv.Itoa(node.Val)
	pre_order(node.Left, data)
	pre_order(node.Right, data)

}


func BST_insert(node *TreeNode, insert_node *TreeNode) {
	// 放在左边
	if insert_node.Val < node.Val {
		if node.Left != nil {
			BST_insert(node.Left, insert_node)
		} else {
			node.Left = insert_node
		}
	}
	if insert_node.Val > node.Val {
		if node.Right != nil {
			BST_insert(node.Right, insert_node)
		} else {
			node.Right = insert_node
		}
	}
}
/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * data := obj.serialize(root);
 * ans := obj.deserialize(data);
 */
```