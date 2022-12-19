```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        //Z形遍历
        List<List<Integer>> res = new ArrayList<>();
        helper(res,root,0);
        return res;
    }

    public void helper(List<List<Integer>> res,TreeNode root,int depth){
        if(root == null) return;
        if(res.size() == depth) res.add(new ArrayList<Integer>());
        if(depth % 2 == 0)  res.get(depth).add(root.val);
        else res.get(depth).add(0,root.val);
        helper(res,root.left,depth+1);
        helper(res,root.right,depth+1);
    }
}
```
