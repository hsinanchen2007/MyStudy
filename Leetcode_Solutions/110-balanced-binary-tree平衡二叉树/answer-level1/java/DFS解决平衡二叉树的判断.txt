### 解题思路
1. 终止条件
2. 把递归看成单次的处理，应该做什么
3. 返回的值是什么

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
       if(root == null) return true;

       return Math.abs(isDepth(root.left)-isDepth(root.right)) <=1 && isBalanced(root.left) &&isBalanced(root.right); 

    }
    private int isDepth(TreeNode root){
        //终止条件
        if(root == null) return 0;
        // 返回什么
        return Math.max(isDepth(root.left),isDepth(root.right))+1;


    }
}
```