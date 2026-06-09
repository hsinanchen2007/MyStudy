### 解题思路
递归，把所有的路都加起来，求和

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
    private int paramSum = 0;
    private boolean flag = false;
    

    public boolean hasPathSum(TreeNode root, int sum) {
        paramSum = sum;
        getSum(root, 0);
        return flag;
    }

    public int getSum(TreeNode root, int total) {
        if (root == null) {
            return 0;
        }
        int num = total + root.val;
        if (root.left == null && root.right == null && num == paramSum) {
            flag = true;
        }
        getSum(root.left, num);
        getSum(root.right, num);
        return total;
    }
}
```