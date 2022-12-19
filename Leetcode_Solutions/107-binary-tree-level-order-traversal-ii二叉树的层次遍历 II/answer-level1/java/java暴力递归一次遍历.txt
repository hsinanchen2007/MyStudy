```java
    private List<List<Integer>> ans;

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        ans=new ArrayList<>();
        if (root==null)return ans;
        dodo(root,0);
        Collections.reverse(ans);
        return ans;
    }


    public void dodo(TreeNode root,int depth){
        depth++;
        if (ans.size()<depth)ans.add(new ArrayList<>());
        List<Integer> list = ans.get(depth - 1);
        list.add(root.val);
        if (root.left!=null)dodo(root.left,depth);
        if (root.right!=null)dodo(root.right,depth);
    }
```
