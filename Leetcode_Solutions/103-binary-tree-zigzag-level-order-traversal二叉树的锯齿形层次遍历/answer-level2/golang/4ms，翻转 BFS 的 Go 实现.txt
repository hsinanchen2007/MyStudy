
![image.png](https://pic.leetcode-cn.com/0d15319f74d5ccb44faaecffd1fceff1b774ab5f5b8b725d41613b8133dbe28a-image.png)

用一个当前层次队列暂存当前层次的所有节点，当队列为空时，将当前层次队列翻转，然后补充到队列中，继续 bfs，这样可以保证每个层次的节点遍历顺序都是翻转的。

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
func zigzagLevelOrder(root *TreeNode) [][]int { // bfs
    result := [][]int{}      
    q := []Node{}        // 队列
    q = append(q, Node{0, root})
    curq := []Node{}    // 当前层次队列
    curLevel := 0
    curLevelArr := []int{}    // 记录当前层次所有节点
    for len(q)!=0 || len(curq)!=0 {
        if len(q)==0 {
            for i,j := 0,len(curq)-1; i<j; i++ {    // 翻转当前层次队列
                curq[i],curq[j] = curq[j],curq[i]
                j--
            }
            q = append(q, curq...)
            curq = []Node{}             // 清空当前层次队列
            
            result = append(result, curLevelArr)
            curLevelArr = []int{}           // 重置当前层次数组
            curLevel++
            
            continue
        }
        cur := q[0]     // 取队首元素
        q = q[1:]       // 删除队首元素
        if cur.node == nil {    // 空节点不放入队列
            continue
        }
        curLevelArr = append(curLevelArr, cur.node.Val) // 添加当前层次的节点
        // 将当前节点的子节点加入队列，要保持翻转的顺序
        if curLevel%2==0 {
            curq = append(curq, Node{cur.level+1, cur.node.Left})
            curq = append(curq, Node{cur.level+1, cur.node.Right})
        } else {
            curq = append(curq, Node{cur.level+1, cur.node.Right})
            curq = append(curq, Node{cur.level+1, cur.node.Left})
        }
    }
    if len(curLevelArr)==0 {
        return result
    }
    result = append(result, curLevelArr)
    return result
}
```