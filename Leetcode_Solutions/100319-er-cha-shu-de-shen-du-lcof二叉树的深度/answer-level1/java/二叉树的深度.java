### 解题思路
凡是树的问题一般都用递归来做，这就要考虑如何用左边的树，结合右边的树，计算出最终的答案。
对于本题而言，二叉树的最大深度，如何计算。对于根节点来说其计算应当是：
1+Math.max(左子树的最大高度，右子树的最大高度)
其中1是根节点的高度。
因此，接下来考虑递归终止条件：
本题中递归终止条件为：当节点为null时，此时节点的高度为0.
当然，最后边界条件不要忘记考虑，当root为null时，直接返回0即可。
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }
        return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
    }
}
```