### 解题思路
bfs

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> list = new ArrayList();
            for(int i=0;i<size;i++){
                TreeNode node = queue.poll();
                if(ans.size()%2==0){
                    list.add(node.val);
                }else{
                    list.add(0,node.val);
                }
                if(node.left!=null){
                    queue.offer(node.left);
                }
                if(node.right!=null){
                    queue.offer(node.right);
                }
            }
            ans.add(list);
            // 1.0
            // if(ans.size()%2==0){
            //     ans.add(list);
            // }
            // else{
            //     Collections.reverse(list);
            //     ans.add(list);
            // }
        }
        return ans;
    }
}
```