/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
    if (root == nil) {
        return nil
    }
    if (key < root.Val) {
        root.Left = deleteNode(root.Left, key)
        return root
    } else if (key > root.Val) {
        root.Right = deleteNode(root.Right, key)
        return root
    } else {
        if (root.Left == nil) {
            return root.Right
        }
        if (root.Right == nil) {
            return root.Left
        }
        // new 和 make的区别，要记住
        //通过make创建对象 make只能创建slice  chan map
        //make 只能用来分配及初始化类型为 slice、map、chan 的数据。new 可以分配任意类型的数据；
        //new 分配返回的是指针，即类型 *Type。make 返回引用，即 Type；
        //new 分配的空间被清零。make 分配空间后，会进行初始化；
        //make 函数只用于 map，slice 和 channel，并且不返回指针
        node := new(TreeNode)
        node = findMin(root.Right)
        root.Val = node.Val
        root.Right = deleteNode(root.Right, node.Val)
    }
    return root
}

func findMin(node *TreeNode) *TreeNode {
    for {
        // golang 没有while
        if node.Left == nil {
            break
        }
        node = node.Left
    }
    return node
}