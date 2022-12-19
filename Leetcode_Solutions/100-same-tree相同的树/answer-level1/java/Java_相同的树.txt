### 解题思路
见到树形结构，由于左子树和右子树和原树具有相同的数据结构，要遍历二叉树，考虑使用递归
1. 若p和q均为null，返回true；
2. 若p和q有一个为null，另一个非null,返回false；
3. 一棵二叉树由三部分构成：当前节点，左子树，右子树；先判断当前节点是否相同，若不同，显然两棵树不同(直接返回false)，再用递归判断左子树和右子树。

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null&&q==null) return true;
        if(p==null&&q!=null||p!=null&&q==null) return false;
        return p.val==q.val&&isSameTree(p.left, q.left)&&isSameTree(p.right, q.right);
    }
}
```