### 解题思路
使用队列

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
        LinkedList<TreeNode> queue = new LinkedList<>();
        if(root == null){
            return res;
        }
        queue.addLast(root);
        while (!queue.isEmpty()){
            int level = queue.size();
            List<Integer> tmp = new LinkedList<>();
            for (int i = 0; i < level; i++) {
                TreeNode cur = queue.pollFirst();
                tmp.add(cur.val);
                if(cur.left != null) queue.addLast(cur.left);
                if(cur.right != null) queue.addLast(cur.right);
            }
            res.add(tmp);
        }
        return res;
    }
}
```