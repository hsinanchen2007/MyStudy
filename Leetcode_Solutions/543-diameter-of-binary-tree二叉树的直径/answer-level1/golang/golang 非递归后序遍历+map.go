1.每个节点的最大直径等于每个节点左右子树最大深度的和
2.想要遍历到当前节点时获取子树的结果, 需要后序遍历(左右子树已经遍历过)
3.非递归后序遍历, 节点的计算结果需要保存到 map 方便存取

```golang []
// 非递归后序遍历 + map 解决
// 时间 O(n)
// 空间 O(n) 保存每个节点的计算值，用栈遍历了每个节点
func diameterOfBinaryTree(root *TreeNode) int {
    
    if root == nil {
        return 0
    }

    max := 0
    stack := []*TreeNode{} // slice 栈, 用来遍历
    mMaxlens := make(map[*TreeNode]int) // 保存每个节点的最大深度
    curr := root
    var prev *TreeNode // 记录上一个遍历节点

    for curr != nil || len(stack) != 0 {
        for curr != nil { // 一直到最左
            stack = append(stack, curr)
            curr = curr.Left
        }

        curr = stack[len(stack) - 1] // 取值不退栈

        if curr.Right == nil || curr.Right == prev { // 无右孩子或有孩子已遍历, 当前节点退栈
            curr = stack[len(stack) - 1]
            stack = stack[:len(stack) - 1]

            // 获取当前节点的左右子树的最大深度(应为是后序遍历, 子树的结果已经计算保存)
            var lDep, rDep int
            if v, ok := mMaxlens[curr.Left]; ok {
                lDep = v
            }
            if v, ok := mMaxlens[curr.Right]; ok {
                rDep = v
            }
            // 保存当前节点的最大路径
            if lDep > rDep {
                mMaxlens[curr] = lDep + 1
            } else {
                mMaxlens[curr] = rDep + 1
            }
            // 记录最大直径
            if max < lDep + rDep {
                max = lDep + rDep
            }

            prev = curr // 记录上一个节点
            curr = nil // 开启下一个循环
        } else { // 有右孩子且没遍历过
            curr = curr.Right
        }
    }

    return max
}
```
