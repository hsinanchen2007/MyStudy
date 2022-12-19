```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root==null) return 0;
        Queue <TreeNode>que = new LinkedList<TreeNode>();
        que.offer(root);
        int i = 0;
        while (!que.isEmpty()){
            int a = que.size();
            i++;
            while (a>0){
                TreeNode tree = que.poll();
                a--;
                if(tree.left!=null) que.offer(tree.left);
                if(tree.right!=null) que.offer(tree.right);
            }
        }
        return i;
    }
}
```
