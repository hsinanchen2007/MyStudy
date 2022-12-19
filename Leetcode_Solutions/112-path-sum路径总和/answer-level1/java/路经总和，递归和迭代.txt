递归法，深度优先遍历
```Java
class Solution {
    public boolean dfs(TreeNode root, int val){
        if(root==null) return false;
        if(root.right==null && root.left==null && root.val==val) return true;
        if(dfs(root.left,val-root.val)) return true;
        else return dfs(root.right,val-root.val);
    }
    public boolean hasPathSum(TreeNode root, int sum) {
        return dfs(root,sum);
    }
}
```

迭代法
```
public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null) return false;
        Stack<TreeNode> st=new Stack();
        Stack<Integer> ss=new Stack();
        st.push(root);ss.push(sum-root.val);
        TreeNode cur; int cursum;
        while(st.isEmpty()==false){
            cur=st.pop();cursum=ss.pop();
            if(cur.left==null && cur.right==null && cursum==0) return true;
            if(cur.left!=null){
                st.push(cur.left);ss.push(cursum-cur.left.val);
            }
            if(cur.right!=null){
                st.push(cur.right);ss.push(cursum-cur.right.val);
            }
        }
        return false;
    }
```

