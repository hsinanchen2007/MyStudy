### 解题思路
BST特征就是left < root < right，每次判断和当前节点的大小即可，小于当前节点，往左子树迭代，大于当前节点，往右子树迭代。用一个指针记录当前访问节点，新元素根据cmp决定插入当前访问节点的左孩子还是右孩子

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        TreeNode node = root;
        int cmp;
        TreeNode preNode;// 上一个访问的节点
        do {
            preNode = node;
            cmp = val - node.val;
            if (cmp < 0){
                node = node.left;
            }else if (cmp > 0){
                node = node.right;
            } else {
                return root;
            }
        } while (node != null);
        TreeNode newNode = new TreeNode(val);
        if (cmp < 0) {
            preNode.left = newNode;
        } else {
            preNode.right = newNode;
        }
        return root;
    }
}
```