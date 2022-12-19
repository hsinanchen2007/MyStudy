给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
![image.png](https://pic.leetcode-cn.com/163e2719059d12e4ff75574b21a7438985e44ec4f25ccb77958ae9656b867d0e-image.png)
遍历的每层，并把最右的节点值加入到结果列表中。

```
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
        List<Integer> res = new LinkedList<>();
        if(root == null) return res;
        queue.add(root);
        while(!queue.isEmpty()){
            int count = queue.size();
            while(count-- >0){
                TreeNode tmpNode= queue.poll();
                if(tmpNode.left != null){
                    queue.add(tmpNode.left);
                }
                if(tmpNode.right != null){
                    queue.add(tmpNode.right);
                }
                if(count == 0){
                    res.add(tmpNode.val);
                }
            }
        }
        return res;
    }
}
```
