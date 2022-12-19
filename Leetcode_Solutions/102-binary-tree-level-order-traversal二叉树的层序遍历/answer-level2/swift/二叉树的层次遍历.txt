
对于树的遍历有DFS(深度优先遍历)和BFS(广度优先遍历)

方法一: DFS深度优先搜索：
思想: 以深度为优先级，从根节点开始一直到达叶子结点，再返回根到达另一个分支。
可以细分为先序遍历，中序遍历和后序遍历。
递归思想
```
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int){
        self.val = val
        self.left = nil
        self.right = nil
    }
}

var result: [[Int]] = []

func levelOrder(_ node: TreeNode, level: Int) {
    if result.count == level {
        result.append([node.val])
    } else {
        var tmp = result[level]
        tmp.append(node.val)
        result[level] = tmp
    }
    if let left = node.left {
        levelOrder(left, level: level + 1)
    }
    if let right = node.right {
        levelOrder(right, level: level + 1)
    }
}

func levelOrder(_ root: TreeNode?) -> [[Int]] {
    guard let tree = root else {return []}
    levelOrder(tree, level: 0)
    return result
}
```

方法二: BFS广度优先搜索
思想: 按照高度顺序一层一层地访问，高层的结点会比低层的结点先被访问到。
相当于层次遍历--利用队列的方式
 
```
//广度优先遍历BFS
func levelOrder(_ root: TreeNode?) -> [[Int]] {
    guard let tree = root else { return [] }
    //创建队列
    var queue: [TreeNode] = [tree]
    var result: [[Int]] = []
    //临时存储队列
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
    return result
}
```
