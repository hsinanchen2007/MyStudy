
右孩子DFS遍历，每一层第一个遍到的加入数组，即为右视图

```
class Solution {
    func rightSideView(_ root: TreeNode?) -> [Int] {
        var ret : [Int] = []

        func dfs(root: TreeNode?, level : Int) {
            if root == nil {
                return
            }

            if level == ret.count, let v = root?.val {
                ret.append(v)
            }

            dfs(root: root?.right, level: level + 1)
            dfs(root: root?.left, level: level + 1)
         }

         dfs(root: root, level: 0)
         return ret
    }
}
```
