```
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    maxD := 0
    curLevel := 0
    cur := root
    var mostRight *TreeNode
    
    for cur != nil {
        mostRight = cur.Left
        if mostRight != nil { // 有左子树， 会来到两次，所以放到第二次和最大深度比较
            mostRightDepth := 1
            for mostRight.Right != nil && mostRight.Right != cur {
                mostRightDepth++
                mostRight = mostRight.Right
            }
            if mostRight.Right == nil {
                curLevel++              //更新Level
                mostRight.Right = cur
                cur = cur.Left
                continue
            } else {// == cur
                curLevel = curLevel - mostRightDepth
                mostRight.Right = nil
            }
        } else {//只会来到一次, 说明是从父节点来的
            curLevel++     
            //if curLevel > maxD { 其实放到这里，会更合理一些
              //maxD = curLevel
            //}
        }
        if curLevel > maxD {//其实最大深度肯定是叶子节点产生的，所以放到只会来到一次的节点(没有左子树的节点)，效率还会提高一些
            maxD = curLevel
        }
        cur = cur.Right
    }
    return maxD
}
```
