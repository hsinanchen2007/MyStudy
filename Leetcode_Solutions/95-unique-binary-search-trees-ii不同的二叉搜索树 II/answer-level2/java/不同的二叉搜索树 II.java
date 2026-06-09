### 解题思路
假设数n产生了a棵树，n+1产生的树是基于这a棵树而来的。具体来讲，对这a棵树的每一棵，都尝试在其每一层插入n+1，每次成功插入就得到了一棵新树。
因为n+1肯定比这些树的每一个节点都大，所以寻找插入层级时只需往右子树寻找。如果将要插入的节点已被占据，那么这个被占据的旧节点将会成为新节点的左子树。

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
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> list1 = new ArrayList<>();
        List<TreeNode> list2 = new ArrayList<>();
        if (n == 0) {
            return list2;
        } else {
            list2.add(new TreeNode(1));
        }
        for (int i = 2; i <= n; i++) {
            list1 = new ArrayList<>(list2);
            list2.clear();
            for (TreeNode treeNode : list1) {
                for (int level = 1; level <= i; level++) {
                    TreeNode duplicate = duplicateTree(treeNode);
                    if (level == 1) {
                        TreeNode newNode = new TreeNode(i);
                        newNode.left = duplicate;
                        list2.add(newNode);
                    } else {
                        TreeNode node = duplicate;
                        for (int j = 2; j < level && node != null; j++) {
                            node = node.right;
                        }
                        if (node != null) {
                            if (node.right == null) {
                                node.right = new TreeNode(i);
                            } else {
                                TreeNode newRight = new TreeNode(i);
                                newRight.left = node.right;
                                node.right = newRight;
                            }
                            list2.add(duplicate);
                        }
                    }
                }
            }
        }
        return list2;
    }

    private TreeNode duplicateTree(TreeNode treeNode) {
        if (treeNode == null) {
            return null;
        }
        TreeNode newNode = new TreeNode(treeNode.val);
        newNode.left = duplicateTree(treeNode.left);
        newNode.right = duplicateTree(treeNode.right);
        return newNode;
    }
}
```