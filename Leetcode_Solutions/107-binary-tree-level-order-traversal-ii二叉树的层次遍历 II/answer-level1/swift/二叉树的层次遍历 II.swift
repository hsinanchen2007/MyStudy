对于树的遍历有DFS(深度优先遍历)和BFS(广度优先遍历)
先从根遍历,然后得到二维数组,最后再翻转一下即可

解法一: DFS深度优先搜索
思想: 以深度为优先级，从根节点开始一直到达叶子结点，再返回根到达另一个分支。
可以细分为先序遍历，中序遍历和后序遍历。
递归思想,再翻转
```
//深度优先遍历DFS
var result: [[Int]] = []

func levelOrderBottom(_ node: TreeNode, level: Int) {
    if result.count == level {
        result.append([node.val])
    } else {
        var temp = result[level]
        temp.append(node.val)
        result[level] = temp
    }
    if let left = node.left {
        levelOrderBottom(left, level: level + 1)
    }
    if let right = node.right {
        levelOrderBottom(right, level: level + 1)
    }
}

func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
    guard let tree = root else { return [] }
    levelOrderBottom(tree, level: 0)
    let resultArr: [[Int]] = result.reversed()
    return resultArr
}
```

解法二:  BFS广度优先搜索

思想: 按照高度顺序一层一层地访问，高层的结点会比低层的结点先被访问到。
相当于层次遍历--利用队列的方式,再翻转
```
//广度优先遍历
func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
    guard let tree = root else { return [] }
    //创建队列
    var queue: [TreeNode] = [tree]
    var result: [[Int]] = []
    var nextLevelQueue: [TreeNode] = []
    
    while queue.count != 0 {
        var temp: [Int] = []
        for node in queue {
            temp.append(node.val)
            if let left = node.left {
                nextLevelQueue.append(left)
            }
            if let right = node.right {
                nextLevelQueue.append(right)
            }
        }
        result.append(temp)
        queue.removeAll()
        queue = nextLevelQueue
        nextLevelQueue.removeAll()
    }
    let resultArr: [[Int]] = result.reversed()
    return resultArr
}
```
