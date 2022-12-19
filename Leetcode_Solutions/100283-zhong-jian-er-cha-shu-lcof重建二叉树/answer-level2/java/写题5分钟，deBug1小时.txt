### 解题思路
这个题思路比较简单，但是要写出来还是有一定难度
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1, inorder, 0, inorder.length -1);
    }
    // 前序数组，子树左边第一位，子树最后一位，后序数组，左边第一位，右边第一位
    private TreeNode helper(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        if(preEnd < preStart || inEnd < inStart) return null;

        // 中间节点
        int val = preorder[preStart];
        TreeNode node = new TreeNode(val);

        if(preStart == preEnd || inStart == inEnd) return node;

        // 计算中间相同节点，point代表前序个数
        int num = 0;
        // 这里刚开始没有+instart,debug一个小时才发现
        while(val != inorder[num + inStart]) num ++;

        node.left = helper(preorder, preStart + 1, preStart + num, inorder, inStart, inStart + num - 1);
        node.right = helper(preorder, preStart + num + 1, preEnd, inorder, inStart + num + 1, inEnd);
        return node;
    }
}
```