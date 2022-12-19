### 解题思路
递归方法，和反转链表的递归思路比较像，递归假定已经完成了对左子树和右子树的展开，然后将root的right指向左子树的头结点，将原右子树的头结点链接到左子树的尾结点上。

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
    public void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.left); // 左子树已经展开了
        flatten(root.right); // 右子树已经展开了

        TreeNode temp = root.right; // 保存右子树的头结点
        root.right = root.left;  // 将右子树替换为左子树
        root.left = null;  // 左子树置空
        // 遍历新的右子树到尾（原来的左子树），将保存的原右子树的头结点链接上去
        while (root.right != null) root = root.right;
        root.right = temp;
    }
}
```