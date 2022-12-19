### 解题思路
此处撰写解题思路
题目中需要的是深度，给定的函数也是int类型，因此可以在函数上直接尝试做递归操作，我们可以从底向上，这样每次只需要记录下左右子树的深度，而根节点的深度就是左右子树深度最大的加上1
递归出口： 如果节点为空则返回0，表示已经遍历到叶子节点了
递归操作：int一个left，right，进行递归
返回操作：root的深度就是left以及right最大的一个加上1

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
    public int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        return left > right ? 1+left : 1+right;
    }
}
```