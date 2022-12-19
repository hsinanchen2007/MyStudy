层序遍历，取最后一个
`func rightSideView(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }

    nodes := make([]*TreeNode, 0)
    ret := make([]int, 0)
    nodes = append(nodes, root)
    for len(nodes) > 0 {
        ret = append(ret, nodes[len(nodes)-1].Val)
        newNodes := []*TreeNode{}
        for i := 0; i < len(nodes); i++ {
            if nodes[i].Left != nil {
                newNodes = append(newNodes, nodes[i].Left)
            }
            if nodes[i].Right != nil {
                newNodes = append(newNodes, nodes[i].Right)
            }
        }
        nodes = newNodes
    }
    return ret 
}`