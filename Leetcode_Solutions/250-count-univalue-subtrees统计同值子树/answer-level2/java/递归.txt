### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
44.19%
的用户
内存消耗 :
37.8 MB
, 在所有 Java 提交中击败了
10.00%
的用户
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
    private int res;
    public int countUnivalSubtrees(TreeNode root) {
        res = 0;
        if (root == null) return res;
        judge(root);
        return res;
    }
    private boolean judge(TreeNode root){
        boolean isSame = true;
        if (root.left != null) isSame = judge(root.left) && root.val == root.left.val && isSame;
        if (root.right != null) isSame = judge(root.right) && root.val == root.right.val && isSame;
        if (isSame) res++;
        return isSame;
    }
}
```