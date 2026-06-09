### 解题思路
递归到每一个节点root时，计算root.left和root.right的高度，如果高度差大于1，表示不符合平衡条件，返回false；否则，进入下一次递归。
执行用时 :1 ms, 在所有 Java 提交中击败了99.89%的用户
内存消耗 :41.4 MB, 在所有 Java 提交中击败了11.19%的用户

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
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        if(Math.abs(getHeight(root.left)-getHeight(root.right))>1) return false;
        else return isBalanced(root.left)&&isBalanced(root.right);
    }
    //计算节点高度的方法
    static int getHeight(TreeNode root){
        if(root==null) return 0;
        return Math.max(getHeight(root.left),getHeight(root.right))+1;
    }
}
```