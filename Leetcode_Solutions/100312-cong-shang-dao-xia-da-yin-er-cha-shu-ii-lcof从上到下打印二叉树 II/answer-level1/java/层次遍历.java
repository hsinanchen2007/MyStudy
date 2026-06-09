也就是在层次遍历的过程中把每一层添加到集合中了/

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
        if(root == null)
            return new ArrayList<>();
        
        List<List<Integer>> lists = new ArrayList<>();

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while(!queue.isEmpty()){
            List<TreeNode> nodes = new ArrayList<>();
            List<Integer> val = new ArrayList<>();

            while(!queue.isEmpty()){
                nodes.add(queue.poll());
            }
            while(!nodes.isEmpty()){
                TreeNode node = nodes.get(0);

                if(node.left != null)
                    queue.offer(node.left);
                if(node.right != null)
                    queue.offer(node.right);

                val.add(node.val);
                nodes.remove(0);
            }
            lists.add(val);
        }
        return lists;
    }
}
```