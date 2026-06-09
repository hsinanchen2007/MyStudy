# 思考

DFS

- 终止条件、返回值和递归过程：
  - 当前节点root为空时，说明此树的高度为0，0也是最小值
  - 当前节点root的左子树和右子树都为空时，说明此树的高度为1，1也是最小值。
  - 如果为其他情况，则说明当前节点有值，且需要分别计算其左右子树的最小深度，返回最小深度+1，+1表示当前节点存在有1个深度
- 时间复杂度是O(N)，N为树的节点数量

# Go实现

```go
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }
    var ans int
    if root.Left != nil {
        ans = Min(minDepth(root.Left), ans)
    }
    if root.Right != nil {
        ans = Min(minDepth(root.Right), ans)
    }
    return ans + 1
}

func Min(a, b int) int {
    if a == 0 {
        return b
    } else if b == 0 {
        return a
    }
    if a < b {
        return a
    }
    return b
}
```

## 代码优化
学习自[ElliotXX](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/12msdfs-de-go-shi-xian-by-elliotxx/)

```go
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return Min(minDepth(root.Left), minDepth(root.Right)) + 1
}

func Min(a, b int) int {
    if a == 0 {
        return b
    } else if b == 0 {
        return a
    }
    if a < b {
        return a
    }
    return b
}
```

# BFS 迭代实现

```go
// Time: O(n), Space: O(n)
func minDepthIterative(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var queue []*TreeNode       // 辅助队列
    queue = append(queue, root) // 根节点入队
    depth := 1                  // 初始化深度为1

    for len(queue) > 0 {   // 当队列不为空时，将队列中的元素出队
        size := len(queue) // 当前队列中元素个数size作为限定:当前层级中节点的数量
        for i := 0; i < size; i++ { // 每次只取当前层级中的节点
            s := queue[0]     // 获取队首元素
            queue = queue[1:] // 弹出队首元素
            if s.Left == nil && s.Right == nil {
                return depth // 叶子节点直接返回当前累计深度
            }
            if s.Left != nil { // 左子树不为空把左子树入队
                queue = append(queue, s.Left)
            }
            if s.Right != nil { // 右子树不为空把右子树入队
                queue = append(queue, s.Right)
            }
        }
        depth++ // 该层级节点已经访问完，深度+1
    }
    return depth // 一定会访问叶子节点并返回，不会走到这里
}
```