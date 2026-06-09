### 解题思路\
利用BST性质
还有一种思路就是TOPK问题的通解，就是直接建小顶堆/大顶堆。但这题没必要，BST的中序遍历下来直接就是有序的数组了。
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
39.1 MB
, 在所有 Java 提交中击败了
100.00%
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
    private int k, res;
    public int kthLargest(TreeNode root, int k) {
        this.k = k;
        dfs(root);
        return res;
    }

    private void dfs(TreeNode root){
        if (root == null) return;
        dfs(root.right);
        if (--k == 0) res = root.val;
        dfs(root.left);
    }
}
```