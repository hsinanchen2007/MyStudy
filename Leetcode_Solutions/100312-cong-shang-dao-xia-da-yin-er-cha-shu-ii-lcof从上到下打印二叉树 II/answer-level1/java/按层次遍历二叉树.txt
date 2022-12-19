### 解题思路
按层次遍历二叉树，需要采用一个count 代表的是每一层的size大小；
遍历每一层都需要存入一个新的list中
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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            int count = queue.size();
            List<Integer> list = new LinkedList<>();
            while(count-->0){
                TreeNode node = queue.poll();
                if(node!=null){
                    list.add(node.val);
                    queue.add(node.left);
                    queue.add(node.right);
                }
            }
            if(!list.isEmpty()){
                res.add(list);
            }
        }
        return res;
    }
}
```