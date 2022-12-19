### 解题思路
基本的BFS遍历

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
        List<List<Integer>> results = new ArrayList<>();
        if(root == null){
            return results;
        }
        ArrayDeque<TreeNode> elements = new ArrayDeque<TreeNode>();
        elements.addLast(root);
        while(!elements.isEmpty()){
            List<Integer> r = new ArrayList<>();
            for(int i = elements.size(); i > 0; i--){
                TreeNode treeNode = elements.removeFirst();
                if(treeNode.left != null){
                    elements.addLast(treeNode.left);
                }
                if(treeNode.right != null){
                    elements.addLast(treeNode.right);
                }
                r.add(treeNode.val);
            }
            results.add(r);
            
        }
        return results;
    }
}
```