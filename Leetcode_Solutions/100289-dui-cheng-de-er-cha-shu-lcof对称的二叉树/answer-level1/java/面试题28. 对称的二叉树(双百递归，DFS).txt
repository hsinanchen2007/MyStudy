### 解题思路
对称二叉树的特性：同一高度的节点用数组a存储可发现a[0]等于a[n]，a[1]等于a[n-1]。。。
主要思路：
1.判空
2.非空就开始比较函数：
2.1左右子树都为空，返回true
2.2左右子树一空返回false
2.3左右子树都非空但不等返回false
2.4左右子树相等开始比较左子树的左子树和右子树的右子树，左子树的右子树和右子树的左子树，就是我上面说的堆成二叉树的特性


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
    public boolean isSymmetric(TreeNode root) {
        if(root==null)return true;
        return Compare(root.left,root.right);
    }
    boolean Compare(TreeNode left,TreeNode right){
        if(left==null&&right==null)return true;
        if(left==null||right==null)return false;
        if(left.val!=right.val)return false;
        return Compare(left.left,right.right)&&Compare(left.right,right.left);
    }
}
```