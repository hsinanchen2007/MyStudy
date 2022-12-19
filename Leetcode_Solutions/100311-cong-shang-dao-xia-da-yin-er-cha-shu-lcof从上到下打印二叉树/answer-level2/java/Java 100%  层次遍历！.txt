### 解题思路
层次遍历需要借助于队列！！！
Queue<TreeNode> queue = new LinkedList<TreeNode>();
queue.offer(root);
TreeNode tmp = queue.poll();

创建一个足够大的int数组，返回之前需要根据实际长度进行处理。
Arrays.copyOfRange(result, 0, i);

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
    private int[] result = new int[10001]; 
    public int[] levelOrder(TreeNode root) {
        if (root == null) {
            return new int[0];
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        
        int i = 0;
        while (!queue.isEmpty()) {
            TreeNode tmp = queue.poll();
            result[i++] = tmp.val;
            if (tmp.left != null) {
                queue.offer(tmp.left);
            }
            if (tmp.right != null) {
                queue.offer(tmp.right);
            }
        }

        return Arrays.copyOfRange(result, 0, i);
    }
}
```