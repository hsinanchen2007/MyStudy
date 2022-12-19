### 解题思路
此处撰写解题思路找到一棵树的叶子结点，将两个结点进行交换，再进行向上递归，保证递归的终止条件。

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
    public TreeNode invertTree(TreeNode root) {
       turnTree(root);
        return root;
    }
    void  turnTree(TreeNode T){
        TreeNode Ti;
       if(T == null){
           return;
       } 
       else{
           turnTree(T.left);
           turnTree(T.right);
           Ti = T.left;
           T.left = T.right;
           T.right = Ti; 
       }

    }
}
```