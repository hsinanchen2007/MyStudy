从右至左层序遍历
```java []
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Deque<TreeNode> Q=new LinkedList();
        Q.offer(root);
        TreeNode p=root;
        while(Q.isEmpty()==false){
            p=Q.poll();
            if(p.right!=null) Q.offer(p.right);
            if(p.left!=null) Q.offer(p.left);
        }
        return p.val;
    }
}
```
