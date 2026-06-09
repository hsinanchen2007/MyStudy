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
    private Queue<TreeNode> queue = new ArrayDeque<TreeNode>();

    private List<List<Integer>> res = new ArrayList<List<Integer>>();

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null){
            return res;
        }
        queue.add(root);
        while(!queue.isEmpty()){
            Queue<TreeNode> queue2 = new ArrayDeque<TreeNode>();
            List<Integer> resitem = new ArrayList<Integer>();
            queue.stream().forEach((item)->{
                if(item.left != null){
                    queue2.add(item.left);
                }
                if(item.right != null){
                    queue2.add(item.right);
                }
                resitem.add(item.val);
            });
            res.add(0,resitem);
            queue = queue2;
        }
        return res;
    }
}
```