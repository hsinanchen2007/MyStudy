### 解题思路
二叉搜索树的第K大节点，首先先在二叉树的右子树中递归查找；
采用count计数，如果count==k，说明此时的root就是要找的那个值；
反之在二叉树的左子树中递归查找；
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
    int count = 0 ,res =0;
    public int kthLargest(TreeNode root, int k) {
        if(root==null) return 0;
        kthLargest(root.right,k);
        ++count;
        if(count==k) res =  root.val;
        if(root.left!=null){
            kthLargest(root.left,k);
        }
        return res;
    }
}
```