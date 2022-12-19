### 解题思路
此处撰写解题思路

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
    public int[] levelOrder(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        // BFS
        Queue<TreeNode> queue = new LinkedList<>();
        if (root == null) {
            return new int[0];
        }

        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
            list.add(node.val);
            
        }
        // list转数组
        int[] arr = new int[list.size()];
        Object[] data = list.toArray();
        int i = 0;
        for (Object o : data) {
            arr[i++] = (int)o;
        }
        return arr;
    }
}
```