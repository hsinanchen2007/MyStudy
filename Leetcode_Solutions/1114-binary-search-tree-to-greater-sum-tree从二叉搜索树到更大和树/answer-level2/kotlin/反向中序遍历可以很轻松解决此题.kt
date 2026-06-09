### 解题思路
此处撰写解题思路
题中要得到每个节点比大的值和自身的累加；
如果是中序遍历可以得到从小到大的有序队列，如果想获得从大到小的顺序怎么弄呢，就是反正来就好了，右 根 左，然后每次保存本次数据和前一个数据的和，这样就能存储我们想要的值
### 代码

```kotlin
/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */

class Solution {
    fun bstToGst(root: TreeNode?): TreeNode? {
        if(root==null){
            return null
        }
        modifyNode(root)
        return root
    }

     var cacheTotal = 0
    //右 根 左 把每个节点和队列之前的计算和添加到队列，
    fun modifyNode(root: TreeNode) {
        root.right?.let { modifyNode(it) }
        cacheTotal += root.`val`
        root.`val` = cacheTotal
        root.left?.let { modifyNode(it) }
    }
}
```