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

//Dfs
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root==null)
            return res;
        res.add(root.val);
        BFS(res,1,root);
        return res;
    }
    private void BFS(List<Integer> res,int level,TreeNode cur){
        if(cur.right!=null){
            if(res.size()==level)
                res.add(cur.right.val);
            BFS(res,level+1,cur.right);
        }
        if(cur.left!=null){
            if(res.size()==level)
                res.add(cur.left.val);
            BFS(res,level+1,cur.left);
            
        }
    }
}

//Bfs
class Solution2 {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root==null)
            return res;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        TreeNode cur;
        while(!q.isEmpty()){
            int count = q.size();
            for(int i =0;i<count;i++){
                cur = q.poll();
                if(i+1==count)
                    res.add(cur.val);
                if(cur.left!=null)
                    q.add(cur.left);
                if(cur.right!=null)
                    q.add(cur.right);
            }
        }
        return res;
    }
}
```