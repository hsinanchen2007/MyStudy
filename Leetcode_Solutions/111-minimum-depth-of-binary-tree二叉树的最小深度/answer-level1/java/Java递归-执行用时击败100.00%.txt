### 解题思路
使用类似于求二叉树最大深度的递归方法，但是每一基本单元（单位树）的判断条件不同。除了需要判断root是否为空外，还需要判断root的左子树和右子树的深度是否为0，因为如果某一方向的深度为0的话，说明这一方向没有叶子节点，不应考虑这个方向。为此，我们把这一方向的深度值赋值成另一端的mindepth函数的返回值，这样最后一步Math.min取最小值并返回的时候，能够做到不影响另一方向的返回结果。 

附执行结果：  
执行用时: 0 ms, 在所有 Java 提交中击败了100.00%的用户  
内存消耗: 39.3 MB, 在所有 Java 提交中击败了7.47%的用户  

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
    public int minDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        if(left == 0) left = right;
        if(right == 0) right = left;
        return Math.min(left, right) + 1;
    }
}
```