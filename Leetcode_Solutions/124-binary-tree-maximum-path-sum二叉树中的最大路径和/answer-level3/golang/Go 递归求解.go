```
func maxPathSum(root *TreeNode) int {
    maxSum := -1 << 31
    maxGain(root, &maxSum)
    return maxSum
}

func maxGain(tn *TreeNode, maxSum *int) int {
    if tn == nil {  //叶子节点
        return 0
    }
    left := maxGain(tn.Left, maxSum)
    right := maxGain(tn.Right, maxSum)
    if left < 0 {
        left = 0    //节点值小于0，则不参与路径
    }
    if right < 0 {
        right = 0
    }
    if tn.Val + left + right > *maxSum {
        *maxSum = tn.Val + left + right
    }
    
    //当前节点的路径最大值
    if left > right {
        return tn.Val + left    
    }
    
    return tn.Val + right
}
```
