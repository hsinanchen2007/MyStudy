
![image.png](https://pic.leetcode-cn.com/cd7db6e20e4286822bc239c30ddef7d6e7296d8f7b42d8826ff5449f019a9284-image.png)

经典的 BFS 广度优先遍历题，用队列可以实现

```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Node struct {
    level   int
    node    *TreeNode
}
func levelOrder(root *TreeNode) [][]int { // bfs
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
            result = append(result, curLevelArr)
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
    result = append(result, curLevelArr)
    return result
}
```