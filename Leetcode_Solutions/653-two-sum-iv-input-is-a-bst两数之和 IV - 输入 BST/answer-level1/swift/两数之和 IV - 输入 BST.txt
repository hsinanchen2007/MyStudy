
思路：
使用任意一种遍历方法遍历树，然后再对树进行搜索 k-遍历val 在树中是否存在


```swift []
class Solution {
  func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        guard let root = root else {
            return false
        }
        
        var result = false
        
        inOrder(root) { (val) in
            let target = k - val
            
            guard target != val else {
                return
            }
                       
            var curNode: TreeNode? = root
            
            while let node = curNode {
                if node.val == target {
                    result = true
                    break
                } else if node.val < target {
                    curNode = node.right
                } else {
                    curNode = node.left
                }
            }
        }
        
        return result
        
    }
    
    func inOrder(_ root: TreeNode?, _ excute: (Int) -> Void) {
        
        guard let root = root else {
            return
        }
        
        inOrder(root.left, excute)
        excute(root.val)
        inOrder(root.right, excute)
        
    }
}
```
