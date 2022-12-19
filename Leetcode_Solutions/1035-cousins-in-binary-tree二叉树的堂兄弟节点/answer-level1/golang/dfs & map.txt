### 解题思路
我们用深度优先搜索标记每一个节点，
对于每一个节点 node，它的父亲为 parent，深度为 d，
我们将其记录到 map 中：pmap[node.val] = par 且 dmap[node.val] = d。

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isCousins(root *TreeNode, x int, y int) bool {
    dmap := map[int]int{}
    pmap := map[int]*TreeNode{}
    dfs(root,nil,0,&dmap,&pmap)
    
    return dmap[x] == dmap[y] && pmap[x] !=  pmap[y]
}
//计算depth 
//创建parent map
func dfs(root,parent *TreeNode,d int,dm *map[int]int,pm *map[int]*TreeNode){
    if root == nil {
        return
    }
    (*dm)[root.Val]=d
    (*pm)[root.Val]=parent
    dfs(root.Left,root,d+1,dm,pm)
    dfs(root.Right,root,d+1,dm,pm)
}
```