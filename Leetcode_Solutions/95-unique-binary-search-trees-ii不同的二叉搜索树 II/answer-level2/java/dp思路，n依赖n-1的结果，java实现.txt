### 解题思路
基于dp的实现思路，将n加入一颗1..m (m<n)的树有两种加入方式：
一、n作为根节点，将原树链到左侧-》生成一棵树
二、n加入右子树-》生成多棵树，多棵树仅右子树不同

核心在于addToTree方法，首先创建一个list，然后按照方式一生成一棵树，加入list。然后拷贝根节点和左子树，与右子树的所有结果分别连接，加入list。
要注意对树进行拷贝，不然会改到同一对象，结果就不对了

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
        if (n <= 0) {
            return Collections.emptyList();
        }
        List<TreeNode> dp = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                dp.add(new TreeNode(1));
            } else {
                List<TreeNode> tmp = new ArrayList<>();
                for (TreeNode tree : dp) {
                    tmp.addAll(addToTree(tree, i));
                }
                dp.clear();
                dp.addAll(tmp);
                tmp.clear();
            }

        }
        return dp;
    }

    private List<TreeNode> addToTree(TreeNode tree, int n) {
        if (tree == null) {
            return Arrays.asList(new TreeNode(n));
        }
        List<TreeNode> tmp = new ArrayList<>();
        TreeNode node = new TreeNode(n);
        node.left = copyTree(tree);
        tmp.add(node);
        for (TreeNode node1 : addToList(copyTree(tree.right), n)) {
            TreeNode node2 = new TreeNode(tree.val);
            node2.left = copyTree(tree.left);
            node2.right = node1;
            tmp.add(node2);
        }
        return tmp;
    }

    private TreeNode copyTree(TreeNode treeNode) {
        if (treeNode == null) {
            return null;
        }
        TreeNode newNode = new TreeNode(treeNode.val);
        newNode.left = copyTree(treeNode.left);
        newNode.right = copyTree(treeNode.right);
        return newNode;
    }
}
```