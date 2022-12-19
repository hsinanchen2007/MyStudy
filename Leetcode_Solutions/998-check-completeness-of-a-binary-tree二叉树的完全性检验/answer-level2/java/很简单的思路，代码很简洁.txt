层序遍历

思路：把一颗树的节点（包括空节点）按层序遍历排成一行，当且仅当存在两个相邻节点：前一个为null，后一个不为null时，才不是不是完全二叉树。
如：
```null
       1
      / \
     2   3
    / \   \
   4   5  6
 / \    / 
 7   8  9  
层序遍历序列为：[1, 2, 3, 4, 5, 6, 7, 8, null, null, 9]，其中 null 出现在了9前面，所以不合法
```

```java
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode prev = root;
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();
            if (prev == null && node != null)
                return false;
            if (node != null) {
                queue.add(node.left);
                queue.add(node.right);
            }
            prev = node;
        }
        return true;
    }
}
```
