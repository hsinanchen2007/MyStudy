```
/**
 * 判断逻辑： 1. 广度优先遍历
 *           2. 如果一个节点有右子树没有左子树，直接返回false
 *           3. 如果一个节点既没有左子树也没有右子树，那么以后遇到的必须都是叶子节点
 */
func isCompleteTree(root *TreeNode) bool {
    var queue []*TreeNode
    queue = append(queue, root)
    leaf := false
    for len(queue) > 0 {
        //1. poll()
        root = queue[0]
        queue = queue[1:]

        l := root.Left
        r := root.Right
        //2. 判断
        //如果一个节点的左子树为nil, 右子树不为nil, 返回false
        if l == nil && r != nil {
            return false
        }
        //如果叶子阶段开始， 之后必须全是叶子节点
        if leaf && (l != nil || r != nil) {
            return false
        }

        if l != nil {
            queue = append(queue, l)
        }
        if r != nil {
            queue = append(queue, r)
        } else {
            leaf = true
        }
        
    }

    return true
}
```
