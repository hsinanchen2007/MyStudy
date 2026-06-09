广度遍历思想，记录每一层的数据

```
class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let tree = root else {
            return []
        }
        //创建一个队列
        var queue: [TreeNode] = [tree]
        var result: [[Int]] = []
        
        var nextLevelQueue: [TreeNode] = []
        
        while queue.count != 0 {
            var temp: [Int] = []
            //遍历当前层，并把下一层入队
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
}
```


深度遍历

```
class Solution {
    
    var result: [[Int]] = []
    
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let tree = root else {
            return []
        }
        levelOrder(tree, level: 0) 
        return result
    }
    
    func levelOrder(_ node: TreeNode, level: Int) {
        if result.count == level {
            result.append([node.val])
        } else {
            var tmp = result[level]
            tmp.append(node.val)
            result[level] = tmp
        }
        if let left = node.left {
            levelOrder(left,level: level + 1)
        }
        if let right = node.right {
            levelOrder(right,level: level + 1)
        }
    }
}
```
