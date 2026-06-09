### 解题思路

![image.png](https://pic.leetcode-cn.com/9a93a3aac7872ee69c865f1239f2ce43acd3adacefa24e5d612390e1c6a230b6-image.png)


函数`boolean bst(TreeNode node)`, 使用中序遍历判断是否是 bst, 并使用count 记录当前 bst 树的大小

`int largestBSTSubtree(TreeNode root)`从根节点开始递归, 循环判断 是否是 bst, 如果检查到 bst , 则直接返回 count 

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
     public int largestBSTSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        prev = null;
        count = 0;
        boolean isBst = bst(root);
        if (isBst) {
            return count;
        }
        return Math.max(largestBSTSubtree(root.left), largestBSTSubtree(root.right));
    }

    private TreeNode prev;
    private int count;

    private boolean bst(TreeNode node) {
        boolean result = true;
        if (node.left != null) {
            result = bst(node.left);
        }
        if (prev != null) {
            if (node.val <= prev.val) {
                result = false;
            }
        }
        count++;
        prev = node;
        if (node.right != null) {
            result = result & bst(node.right);
        }
        return result;
    }


}
```