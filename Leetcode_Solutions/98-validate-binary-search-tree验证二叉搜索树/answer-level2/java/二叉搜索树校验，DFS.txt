### 解题思路

深度优先遍历，对每个节点，只需要该节点满足条件：小于最大值，大于最小值。
最大值、最小值根据二叉树的特点更新：
（1）左子树更新最大值，为当前节点值和当前节点限制最大值取小（Long nmax = Math.min(max, root.val)）
（2）右子树更新最小值，为当前节点值和当前节点限制最小值取大（Long nmin = Math.max(min, root.val)）

需要注意的是：
（1）该题中二叉搜索树限制比较严格，不能有取等；
（2）题目限制的数字范围为Integer，因此初始化最大值最小值时，用Long



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
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        return isValidBST_reverse(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean isValidBST_reverse(TreeNode root, Long min, Long max) {
        boolean result = true;
        if (root == null) return true;
        if (root.val <= min || root.val >= max) return false;

        if (root.left!=null) {
            Long nmax = Math.min(max, root.val);
            if(root.left.val<root.val){
                result &= isValidBST_reverse(root.left, min, nmax);
            } else {
                result = false;
            }
        }
        if (root.right!=null) {
            Long nmin = Math.max(min, root.val);
            if(root.right.val>root.val){
                result &= isValidBST_reverse(root.right, nmin, max);
            } else {
                result = false;
            }
        }
        return result;
    }
}
```