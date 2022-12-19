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
   public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> result = new LinkedList<>();
        if(root==null){
            return result;
        }
        Queue<TreeNode> node_queues = new LinkedList<>();
        node_queues.add(root);
        node_queues.add(null);
        LinkedList<Integer> level_list = new LinkedList<>();
        while (!node_queues.isEmpty()){
             TreeNode node = node_queues.poll();
             if(node!=null){
                 level_list.add(node.val);
                 if(node.left!=null){
                     node_queues.add(node.left);
                 }
                 if(node.right!=null){
                     node_queues.add(node.right);
                 }
             }else {
                 result.addFirst(level_list);
                 level_list= new LinkedList<>();
                 if (node_queues.size() > 0) {
                     node_queues.add(null);
                 }
             }
        }
        return result;
    }
}
```