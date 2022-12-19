## 解题思路：
通过找出从根到两个节点的路径，再比较两个路径最后一个共同节点，就是两个节点的最近公共祖先。

函数1，找出路径：
```go
func getPath(root, node *TreeNode) []*TreeNode{
    var res []*TreeNode
    cur := root
    for cur != node {
        res = append(res, cur)
        if node.Val > cur.Val {// 按照二叉搜索树特性，大的节点放右边子树，小的放左边
            cur = cur.Right
        }else{
            cur = cur.Left
        }
    }
    // 最后不能忘记把node节点也放进集合中。
    res = append(res, cur)
    return res
}
```

函数2，遍历两条路径，找出最近公共祖先
```go
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    path1 := getPath(root, p)
    path2 := getPath(root, q)
    var cur *TreeNode
    for i := range path1 {
        if i < len(path2) && path1[i] == path2[i]{//注意长度比较，当两条路径任意一条结束，都需要结束循环
            cur = path1[i]
        }else{
            break
        }
    }
    return cur
}
```

这样的时间复杂度是O(N)，但是系数较大. 不是一个很快的时间复杂度。但是逻辑很清晰。

