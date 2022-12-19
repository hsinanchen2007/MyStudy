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
    int ans = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        ans = 1;
        //int leftdepth = childTreeDepth(root.left);
        //int rightdepth = childTreeDepth(root.right);
        childTreeDepth(root);
        return ans - 1;
    }

    private int childTreeDepth(TreeNode root){
        if(root == null){
            return 0;
        }
        int L = childTreeDepth(root.left);
        int R = childTreeDepth(root.right);
        ans = Math.max(ans, L + R + 1);
        return 1 + Math.max(L, R);
    }
}
```