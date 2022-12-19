### 解题思路
通过层次遍历，每次将尾巴上的那个点加入结果集合中

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
        List<TreeNode> list = new LinkedList<>();
        List<Integer> result = new LinkedList<>();
        if (root == null) {
            return result;
        }
        list.add(root);
        int levelSize = list.size();
        while (true) {
            for (int i=0;i<levelSize;i++) {
                TreeNode node = list.remove(0);
                if (node.left != null) {
                    list.add(node.left);
                }
                if (node.right != null) {
                    list.add(node.right);
                }
                if (i == levelSize-1) {
                    result.add(node.val);
                }
            }
            levelSize = list.size();
            if (levelSize == 0) {
                break;
            }
        }
        return result;
    }
}
```