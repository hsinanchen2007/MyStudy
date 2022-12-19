### 解题思路
此处撰写解题思路
首先看到这道题联系到了有道求树的深度的题，求左子树最大深度，求右子树最大深度然后求和，发现结果不对，然后看了错误的例子，可以发现这种解法不能保证通过根节点就是最大直径。但是可以利用这种思路，既然不能保证通过根节点就是最大直径，那可以直接在递归的过程中求出最大直径。其中递归出口，递归操作以及返回值都和求最大深度那道题一模一样，只需要在中间加一个求最大深度的。

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
    private int ans;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)
            return 0;
            ans = 0;
        deep(root);
        return ans;
        
    }

    public int deep(TreeNode root){
        if(root == null)
            return 0;
        int left = deep(root.left);
        int right = deep(root.right);
        ans = Math.max(ans,left+right);
        return left > right ? left+1 : right+1;
    }
}
```