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
    public List<Double> averageOfLevels(TreeNode root) {
        LinkedList<Double> result = new LinkedList<>();
        Queue<TreeNode> node_queues = new LinkedList<>();
        node_queues.add(root);
        node_queues.add(null);
        LinkedList<TreeNode> level_list = new LinkedList<>();
        while (!node_queues.isEmpty()){
             TreeNode node = node_queues.poll();
             if(node!=null){
                 level_list.add(node);
                 if(node.left!=null){
                     node_queues.add(node.left);
                 }
                 if(node.right!=null){
                     node_queues.add(node.right);
                 }
             }else {
                 result.add(level_list.stream().mapToInt(r ->r.val).average().getAsDouble());
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