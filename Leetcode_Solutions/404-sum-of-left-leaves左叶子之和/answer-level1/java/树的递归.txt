### 解题思路
这题起始还是在考察树的递归实现。
只需要在带一个参数，然后根据这个参数判断是不是叶子，0/1判断是不是左叶子就好了。

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
    private int ans = 0;

    public void preorder(TreeNode node, int flag){
        if(node == null)
            return;
        if(node.left == null && node.right == null && flag == 1)
            ans += node.val;
        preorder(node.left, 1);
        preorder(node.right, 0);
    }

    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null)
            return 0;
        preorder(root, 0); //就只有一个节点是根节点，不是叶子节点。
        return ans;
    }
}
```