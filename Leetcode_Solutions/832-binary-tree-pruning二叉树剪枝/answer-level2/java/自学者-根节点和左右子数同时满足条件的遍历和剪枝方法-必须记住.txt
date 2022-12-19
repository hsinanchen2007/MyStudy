### 解题思路
* 但三个条件同时满足要求时，需要后续遍历
* 当某个子分支不满足要求时直接裁剪掉，左子树裁剪和右子树裁剪
* 最后根据三个条件一起决定是否包含1
* 注意当node为null时是不包含1的，所以直接返回false
* 在获取最终结果时很关键，一般想不到，包含1时：返回root就是根节点，根节点全部为0则返回null

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
    public TreeNode pruneTree(TreeNode root) {
        return containsOne(root) ? root : null;
    }
    private boolean containsOne(TreeNode root) {
        if (root == null) {
            return false;
        }
        boolean leftContain = containsOne(root.left);
        boolean rightContain = containsOne(root.right);
        if(!leftContain) {
            root.left = null;
        }
        if(!rightContain) {
            root.right = null;
        }
        return root.val == 1 || leftContain || rightContain; 
    }
}
```