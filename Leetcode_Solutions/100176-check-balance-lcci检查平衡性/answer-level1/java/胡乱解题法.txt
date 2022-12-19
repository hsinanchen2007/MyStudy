### 解题思路
自顶向下，每个节点比较自身左右两边的最大深度，左右相差大于1则直接return false
然后左右子节点递归，两条线只要有一条不成立则return false

![image.png](https://pic.leetcode-cn.com/9211e671f84af080dc59ca35cb6a9d854698ea9ccc74c42d4c17012b8612aae1-image.png)



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
        if(Math.abs(deep(root.left) - deep(root.right)) > 1) return false;
        return isBalanced(root.left) && isBalanced(root.right);
    }

    private int deep(TreeNode node){
        if(node == null) return 0;
        return Math.max(deep(node.left) + 1, deep(node.right) + 1);
    }
}
```