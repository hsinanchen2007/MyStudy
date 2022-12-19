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
    public List<Integer> rightSideView(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        List<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        while (!queue.isEmpty()) {
            int size = queue.size();
            Stack<Integer> stack = new Stack<>();
            while(size > 0) {
                TreeNode node =  queue.poll();
                stack.push(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
                size--;
            }
            if(!stack.isEmpty()) {
                Integer val = stack.pop();
                res.add(val);
            }
        }
        return res;
    }
}
```