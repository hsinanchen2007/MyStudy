### 解题思路
此处撰写解题思路
### 使用方法前后二叉树结构变化
原始二叉树结构如图：
![二叉树.PNG](https://pic.leetcode-cn.com/8a1a483bb8573ef2a34eb0b5a0ebf8a20cf9241af494e39f868523c4da194eab-%E4%BA%8C%E5%8F%89%E6%A0%91.PNG)
结果树如图：
![线索二叉树.PNG](https://pic.leetcode-cn.com/1d5160d2736232d6a9eb9cfa9e24480f9fc05dfa044565be976ba3d6ca083abe-%E7%BA%BF%E7%B4%A2%E4%BA%8C%E5%8F%89%E6%A0%91.PNG)
结果序列是从顶部节点4开始，不断输出右子节点的值直至右子节点为null.
### 方法大致步骤
1. 设置当前节点current(第一次是树的root节点)后，current != null则进入第二步，否则计算结束；
2. 当current.left是否为null;当current.left == null将current.val的值加入结果序列中，并且current = current.right;当current.left != null时即拥有左子树，找到左子树最右边的节点rightMostNode,并且让rightMostNode的右子节点指向current,并且用一个临时变量temp记录current节点的引用（此处用于后面避免无限循环），当前节点转移至左子树根节点（即：current = current.left）,并且令temp.left = null，如果没有这一步的话current和current.left会相互指向（即current的左子节点是current.left,而current.left的右子节点是current）,那么会造成current.left永远不为null，就会进入无线循环情景；
3. 查找左子树的最右节点。






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
    public List<Integer> inorderTraversal(TreeNode root) {
        TreeNode current = root;
        TreeNode rightMostNode = null;
        List<Integer> res = new ArrayList<>();
        while(current != null) {
        if(current.left == null) {
            res.add(current.val);
            current = current.right;
        } else {
            rightMostNode = findRightMostNode(current.left);
            rightMostNode.right = current;
            TreeNode temp = current;
            current = current.left;
            temp.left = null;
        }
        }
        return res;
    }

    private TreeNode findRightMostNode(TreeNode node) {
        while(node.right != null) {
            node = node.right;
        }
        return node;
    }
}
```