测试用例最后结尾的几个边界条件是真的卡，索性用 Long 了。
```
class Solution {
    var result = true
    fun isValidBST(root: TreeNode?): Boolean {
        dfs(root, Long.MIN_VALUE, Long.MAX_VALUE)
        return result
    }

    private fun dfs(root: TreeNode?, min: Long, max: Long) {
        when {
            !result || root == null -> return
            root.`val` !in min + 1 until max -> result = false
            else -> {
                dfs(root.left, min, root.`val`.toLong())
                dfs(root.right, root.`val`.toLong(), max)
            }
        }
    }
}
```
DFS 解法，给每个数字规定一个范围区间。区间两端分别是父结点和上一个拐点。