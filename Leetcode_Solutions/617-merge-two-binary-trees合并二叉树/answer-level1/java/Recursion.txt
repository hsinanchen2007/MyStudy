### 解题思路
此处撰写解题思路
时间复杂度：O(n)
空间复杂度：O(n),递归通过进栈和出栈来完成，取决于递归的次数
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1==null)        //当t1为空时返回t2
            return t2;
        if(t2==null)
            return t1;
        t1.val=t1.val+t2.val;       //将两棵树的值加起来覆盖在第一棵树上
        t1.left=mergeTrees(t1.left,t2.left);        //不断递归
        t1.right=mergeTrees(t1.right,t2.right);
        return t1;
    }
}
```