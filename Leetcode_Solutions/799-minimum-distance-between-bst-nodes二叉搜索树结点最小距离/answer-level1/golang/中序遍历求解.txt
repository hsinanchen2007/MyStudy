```
var nodeVal []int

func minDiffInBST(root *TreeNode) int {
    nodeVal = make([]int,0)
    minDiffInBSTTool(root)
    min := 100
    
    for i:= 1; i < len (nodeVal); i++ {
        tmp := nodeVal[i]-nodeVal[i-1]
        min = Min(min, tmp)
    } 
    return min 
}

func minDiffInBSTTool(node *TreeNode) {

    if node == nil {
        return
    }

    if node.Left != nil {
        minDiffInBSTTool(node.Left)
    }
   
    nodeVal = append(nodeVal,node.Val)

    if node.Right != nil {
        minDiffInBSTTool(node.Right)
    }

}

func Min(a,b int)int{
    if a < b {
        return a
    }
    return b 
}
```
