### 解题思路
此处撰写解题思路

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

    // 默认值 0
    int res = 0;
   /**
     * 最长同路径问题 -- 即找到节点值相同的最长的路径（的长度）
     * 递归
     * 先找到根节点左子节点的长度 和 右子节点的长度（如果子节点只有一个节点的话，此时返回的长度为0）
     */
    public int longestUnivaluePath(TreeNode root) {
        res = 0;
        arrowLength(root);
        return res;
    }

    /**
     * 该方法返回值为子节点中具有最长同路径的长度
     */
    private int arrowLength(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 获取该节点的左子节点的最长同路径（如果该节点的子节点没有节点了，则返回0 ，因此下边会进行+1，后边的resLeft + lenRight 则为此节点的最长同值节点）
        int lenLeft = arrowLength(root.left);
        int lenRight = arrowLength(root.right);
        int resLeft = 0;
        int resRight = 0;
        // 判断是否和当前根节点的值相同，同则各加一
        if (root.left != null && root.left.val == root.val) {
            resLeft = lenLeft + 1;
        }
        if (root.right != null && root.right.val == root.val) {
            resRight = lenRight + 1;
        }
        // 这里为啥是resLeft + resRight ，这里的res设置为以当节点为根节点时的最长同值路径的长度
        res = Math.max(res, resLeft + resRight);
        // 返回当前最长的一边（左子节点的最长同路径，或者是右节点的最长同路径）
        return Math.max(resLeft, resRight);
    }
}
```