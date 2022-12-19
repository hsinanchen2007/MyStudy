### 解题思路
层次遍历，前中后序遍历都是解题的基础一定要信手拈来的。

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

        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> lists = new ArrayList<>();
        
        queue.offer(root);

        while(!queue.isEmpty()){
            List<Integer> vals = new ArrayList<>();
            List<TreeNode> nodes = new ArrayList<>();
            while(!queue.isEmpty()){
                TreeNode node = queue.poll();
                if(node.left != null)
                    nodes.add(node.left);
                if(node.right != null)
                    nodes.add(node.right);
                vals.add(node.val);
            }
            lists.add(new ArrayList<>(vals));
            while(nodes.size() != 0){
                queue.offer(nodes.get(0));
                nodes.remove(0);
            }
        }
        return lists;
    }
}
```