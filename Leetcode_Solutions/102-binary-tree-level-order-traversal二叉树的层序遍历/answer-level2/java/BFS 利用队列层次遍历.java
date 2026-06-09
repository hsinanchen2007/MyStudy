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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root,res);
        return res;
    }

    public static void helper(TreeNode root, List<List<Integer>> res){
        if (root == null) return ;

        Queue<TreeNode> queue = new ArrayDeque();  
        queue.add(root);
          
        while (!queue.isEmpty()){
            int len = queue.size(); 
            //记录每一层的结果  
            List<Integer> list = new ArrayList<>();
            //取出当前层所有节点(len是队列长度)
            for (int i = 0; i < len; i++ ){
                TreeNode node = queue.poll();
                list.add(node.val);
                //如果该节点有左节点，则放入队列(此时队列size增大，但是不影响遍历，因为len的值早就取出来了)
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            //记录每一层的值集合
            res.add(list);
        }
    }
}
```

第一次写BFS，也是第一次使用队列。通过了很开心。
执行用时 :2 ms, 在所有 Java 提交中击败了83.81% 的用户
内存消耗 :36.3 MB, 在所有 Java 提交中击败了48.84%的用户
