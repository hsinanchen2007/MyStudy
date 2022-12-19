### 解题思路

使用队列进行二叉树层序遍历，保存每层最右侧节点。
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
   public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if (root == null){
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode node = root;
        queue.add(node);
        TreeNode currentLast = node;
        TreeNode nextLast = null;
        while (!queue.isEmpty()){
            node = queue.poll();
            if (node.left!=null){
                queue.add(node.left);
                nextLast = node.left;
            }

            if (node.right != null){
                queue.add(node.right);
                nextLast = node.right;
            }

            if (node == currentLast){
                result.add(node.val);
                currentLast = nextLast;
            }
        }
        return result;
    }
}
```