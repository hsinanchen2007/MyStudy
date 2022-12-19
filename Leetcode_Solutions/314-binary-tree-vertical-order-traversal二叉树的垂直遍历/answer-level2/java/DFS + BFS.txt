思路比较简单，如下：
1. DFS获取坐标范围
2. BFS统计结果
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

    private int left, right;

    public List<List<Integer>> verticalOrder(TreeNode root) {
        left = 0;
        right = 0;
        dfs(root, 0);
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return res;
        }
        for(int i = 0 ; i < Math.abs(left) + right + 1; i++){
            res.add(new ArrayList<>());
        }
        Deque<TreeNode> queue1 = new ArrayDeque<>();
        Deque<Integer> queue2 = new ArrayDeque<>();
        queue1.add(root);
        queue2.add(Math.abs(left));
        while(!queue1.isEmpty()){
            TreeNode node = queue1.poll();
            int col = queue2.poll();
            res.get(col).add(node.val);
            if(node.left != null){
                queue1.add(node.left);
                queue2.add(col - 1);
            }
            if(node.right != null){
                queue1.add(node.right);
                queue2.add(col + 1);    
            }
        }
        return res;
    }

    private void dfs(TreeNode node, int col){
        if(node == null){
            return;
        }
        left = Math.min(left, col);
        right = Math.max(right, col);
        dfs(node.left, col - 1);
        dfs(node.right, col + 1);
    }
}
```