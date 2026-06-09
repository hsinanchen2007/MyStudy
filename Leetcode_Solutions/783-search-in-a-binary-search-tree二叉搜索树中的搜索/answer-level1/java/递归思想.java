### 解题思路
1. 如果当前节点值 == val 则直接返回
2. 根据二叉搜索树性质，左子树所有节点 <= 根节点 <= 右子树所有节点
3. 当根节点 < val ,说明val 相等的节点在右子树上，反之则遍历左子树
![image.png](https://pic.leetcode-cn.com/3e5cd1afc060d98db2194e60bedb984131f62512ddf418a4759f6bd1be92977f-image.png)

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
    public TreeNode searchBST(TreeNode root, int val) {
         if (root == null) {
            return null;
        }
        if (root.val == val) {
            return root;
        } else if (root.val < val) {
            return searchBST(root.right, val);
        } else {
            return searchBST(root.left, val);
        }
    }
}
```