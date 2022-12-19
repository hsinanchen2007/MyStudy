### 解题思路
排队的时候加了一个cut来标记一层结束了，感觉这样比较直观一点。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root==null) return res;
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode cut = new TreeNode(0);
        queue.offer(root);
        queue.offer(cut);
        
        while (queue.size()>1){
            List<Integer> rowRes = new LinkedList<>();
            while (queue.peek()!=cut){
                TreeNode cmp = queue.poll();
                if (cmp.left!=null) queue.offer(cmp.left);
                if (cmp.right!=null) queue.offer(cmp.right);
                rowRes.add(cmp.val);
            }
            queue.poll();
            queue.offer(cut);
            res.add(rowRes);
        }
        return res;
    }
}
```