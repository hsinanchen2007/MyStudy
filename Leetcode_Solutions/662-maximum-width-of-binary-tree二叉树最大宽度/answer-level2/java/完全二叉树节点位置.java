### 解题思路
 解题关键点：完全二叉树父节点与子节点的位置计算：
 左子位置 = 父位置*2 右子位置 = 父位置*2+1；
 据此解题思路：层次搜索树，记录每个节点和他在这一层的位置；

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
    public int widthOfBinaryTree(TreeNode root) {
        
        if (root == null) {
            return 0;
        }
        Map<TreeNode, Integer> map = new HashMap<>();
        List<TreeNode> list = new ArrayList<>();
        list.add(root);
        map.put(root, 0);
        int levelSize = list.size();
        int maxWidth = 0;
        while (true) {
            int left = 0;
            int right = 0;
            for (int i=0;i<levelSize;i++) {
                TreeNode node = list.remove(0);
                int position = map.get(node);
                if (i == 0) {
                    left = position;
                }
                if (i == levelSize -1 ) {
                    right = position+1;
                }
                if (node.left != null) {
                    list.add(node.left);
                    map.put(node.left, position*2);
                }
                if (node.right != null) {
                    list.add(node.right);
                    map.put(node.right, position*2 + 1);
                }
            }
            maxWidth = Math.max(maxWidth, (right - left));
            levelSize = list.size();
            if (levelSize == 0) {
                break;
            }
        }
        return maxWidth;
    }
}
```