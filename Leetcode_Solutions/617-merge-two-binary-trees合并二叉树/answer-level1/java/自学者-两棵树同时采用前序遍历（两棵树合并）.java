### 解题思路
* 两颗树谁的左子树有值，谁的没有值，左右两边都有值三种情况返回被遍历节点
* 认准第一颗树进行覆盖，将第1颗书的左右子树重新赋值。
* 最后返回第一颗树的根节点，就是结果

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
        //从两个树的根节点开始合并，代表是前序遍历
        return preorder(t1,t2);
    }
    
    private TreeNode preorder(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return null;
        }
        if (t1 == null && t2 != null) {
            return t2;
        }
        if (t1 != null && t2 == null) {
            return t1;
        }
        t1.val += t2.val;
        TreeNode left = preorder(t1.left,t2.left);
        TreeNode right = preorder(t1.right,t2.right);
        t1.left = left;
        t1.right = right;
        return t1;
    }
}
```