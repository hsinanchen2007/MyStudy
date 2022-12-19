### 解题思路
深度搜索节点，存储当前搜到节点的深度，返回最大深度对应的第一个节点值即可，一定要从左往右

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
    int deep;
    int value;
    public int findBottomLeftValue(TreeNode root) {
        if (root == null) {
            return 0;
        }
        deep = 0;
        dfs(root, 1);
        return value;
    }
    public void dfs(TreeNode node, int length) {
        if (length > deep) {
            deep = length;
            value = node.val;
        }
        if (node.left != null) {
            dfs(node.left, length+1);
        }
        if (node.right != null) {
            dfs(node.right, length+1);
        }
    }
}
```