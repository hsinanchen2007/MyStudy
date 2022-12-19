### 解题思路

`否则不为 NULL 的节点将直接作为新二叉树的节点`理解为当一个为null时，直接返回另外一个。
`如果两个节点重叠,则值相加`理解为当两个不为null时，用和来替代t1.
然后递归**处理左子树和右子树** 
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {//不需要创建新的节点
        if(t1==null) return t2;
        if(t2==null) return t1;
        t1.val+=t2.val;
        t1.left=mergeTrees(t1.left,t2.left);
        t1.right=mergeTrees(t1.right,t2.right);
        return t1;

    }
}
```