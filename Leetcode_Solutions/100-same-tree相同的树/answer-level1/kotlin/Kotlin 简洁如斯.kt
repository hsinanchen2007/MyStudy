```
class Solution {
    var result = true
    fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
        dfs(p, q)
        return result
    }

    private fun dfs(p: TreeNode?, q: TreeNode?) {
        when {
            !result -> return
            p?.`val` != q?.`val` -> result = false
            p != null -> {
                dfs(p.left, q!!.left)
                dfs(p.right, q.right)
            }
        }
    }
}
```
DFS， 说一下 when 里的判断：
* 结果已经是 false 了，无需再查 return
* p, q 值不同，结果置为 false
* p, q 不为空，继续查左右子树
