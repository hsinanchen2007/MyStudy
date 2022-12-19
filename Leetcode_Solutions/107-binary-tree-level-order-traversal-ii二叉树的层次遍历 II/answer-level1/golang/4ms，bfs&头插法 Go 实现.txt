
![image.png](https://pic.leetcode-cn.com/aa1919368a2c9848f72552aa6b32c5cc3dfe2a7ebaf97df4234fbef5db2af0e4-image.png)

bfs 层次遍历二叉树，在遍历到下一层的时候，将当前层次所有的节点数组插入到结果数组头部，最后输出结果数组。

代码
```
type Node struct {
    level   int
    node    *TreeNode
}
func levelOrderBottom(root *TreeNode) [][]int { // bfs + 头插法
    result := [][]int{}      
    q := []Node{}        // 队列
    q = append(q, Node{0, root})
    curLevel := 0
    curLevelArr := []int{}    // 记录当前层次所有节点
    for len(q)!=0 {
        cur := q[0]     // 取队首元素
        q = q[1:]       // 删除队首元素
        if cur.node == nil {    // 空节点不放入队列
            continue
        }
        if cur.level != curLevel {          // 将当前层次的所有节点加入结果数组
            t := [][]int{curLevelArr}       // 头插法
            result = append(t, result...)
            curLevelArr = []int{}           // 重置当前层次数组
            curLevel++
        }
        curLevelArr = append(curLevelArr, cur.node.Val) // 添加当前层次的节点
        // 将当前节点的子节点加入队列
        q = append(q, Node{cur.level+1, cur.node.Left})
        q = append(q, Node{cur.level+1, cur.node.Right})
    }
    if len(curLevelArr)==0 {
        return result
    }
    t := [][]int{curLevelArr}       // 头插法
    result = append(t, result...)
    return result
}
```