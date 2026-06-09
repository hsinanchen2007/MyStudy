### 解题思路
此处撰写解题思路

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
    int length = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);  
        return length;  
    }
    public int depth(TreeNode root){
        if (root == null){return 0;}
        int L = depth(root.left);
        int R = depth(root.right);
        length =Math.max(length,L+R);
        //选择最深子树作为结果
        return  Math.max(L,R)+1;
    }
}
```