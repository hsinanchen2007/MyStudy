### 解题思路
使用全局变量记录路线数；
递归函数`reverse`用于判断从当前节点出发是否有路径满足条件；
接着对左子树右子树递归主函数。

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
    private int result = 0;
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        reverse(root, sum, 0);
        pathSum(root.left, sum);
        pathSum(root.right, sum);
        return result;
    }

    public void reverse (TreeNode root, int sum, int curr) {
        if (root == null) {
            return;
        }
        curr += root.val;
        if (curr == sum) {
            result += 1;
        }
        reverse(root.left, sum, curr);
        reverse(root.right, sum, curr);
    }
}
```