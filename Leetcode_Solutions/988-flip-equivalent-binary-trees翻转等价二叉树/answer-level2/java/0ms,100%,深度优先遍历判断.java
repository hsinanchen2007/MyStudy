### 解题思路
![屏幕快照 2020-02-29 15.44.01.png](https://pic.leetcode-cn.com/de376675ba557997998557c898c55251a3cabf859d38ce5260e24d5b65ab5389-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-29%2015.44.01.png)


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
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        // 如果两个节点都是空那就返回true
        if (root1 == null && root2 == null) {
            return true;
        }
        // 当两个节点都不为空并且值相等的时候进一步判断
        if (root1 != null && root2 != null && root1.val == root2.val) {
            // 判断左右子节点其中一个为空的情况
            if (root1.left == null) {
                if (root2.left == null) {
                    return flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right);
                } else {
                    return flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left);
                }
            } else if (root1.right == null) {
                if (root2.left == null) {
                    return flipEquiv(root1.right, root2.left) && flipEquiv(root1.left, root2.right);
                } else {
                    return flipEquiv(root1.right, root2.right) && flipEquiv(root1.left, root2.left);
                }
            } 
            // 到这里证明两个节点的左右子节点都不应该为空，如果root2任意子节点为空就是错的
            else if (root2.left == null || root2.right == null) {
                return false;
            } 
            // 判断当前节点是否为反转情况
            else if (root1.left.val == root2.left.val && root1.right.val == root2.right.val) {
                return flipEquiv(root1.left,root2.left) && flipEquiv(root1.right, root2.right);
            } else if (root1.left.val == root2.right.val && root1.right.val == root2.left.val) {
                return flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left);
            } 
        }
        return false;
    }
}
```