### 解题思路
一棵树要想平衡，要满足两点：
1）左右子树高度差为0或1或-1；
2）左右子树也是平衡树；

其实从这个要求就可以看到一个递归函数的雏形，然后我们再用另一个递归函数去求解树的高度即可。

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
        if (root == null) {
            return true;
        }
        if (root.right == null && root.left == null) {
            return true;
        }
        //判断左右子树高度之差是否为1
        int balance = getHigh(root.left) - getHigh(root.right);
        if (balance > 1 || balance < -1) {
            return false;
        }


        return isBalanced(root.left) && isBalanced(root.right);
    }

    public int getHigh(TreeNode root) {
        if(root == null){
            return 0;
        }
        return Math.max(getHigh(root.left),getHigh(root.right)) + 1;
    }
}
```