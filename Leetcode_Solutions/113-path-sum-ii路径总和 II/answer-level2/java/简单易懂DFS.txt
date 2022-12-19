```
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ret = new ArrayList<>();
        dfs(root,sum,ret,new ArrayList<Integer>());
        return ret;
    }
    public void dfs(TreeNode root, int sum, List<List<Integer>> ret,ArrayList<Integer> route){
        if(root == null) return; 
        route.add(root.val);
        int left = sum - root.val;
        if(root.left == null && root.right == null){
            if(left == 0){
                ret.add(route);
                return;
            }else return;
        }
        dfs(root.left,left,ret,new ArrayList<>(route));
        dfs(root.right,left,ret,new ArrayList<>(route));
    }
}
```
