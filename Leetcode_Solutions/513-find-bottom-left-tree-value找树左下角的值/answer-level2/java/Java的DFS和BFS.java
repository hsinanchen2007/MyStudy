深度优先遍历DFS：记录深度最大的第一个节点
```java
class Solution {
    int[] result = new int[]{0,-1};
    public int findBottomLeftValue(TreeNode root) {
        dfs(root,0);
        return result[0];
    }
    public void dfs(TreeNode root,int depth){
        if(root==null) return ;
        if(depth>result[1]){
            result[0] = root.val;
            result[1] = depth;
        }
        dfs(root.left,depth+1);
        dfs(root.right,depth+1);
    }
}
```
广度优先遍历BFS：按照从右往左的层序遍历，最后一个就是结果
```java
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            root = q.poll();
            if(root.right!=null) q.offer(root.right);
            if(root.left!=null) q.offer(root.left);
        }
        return root.val;
    }
}
```