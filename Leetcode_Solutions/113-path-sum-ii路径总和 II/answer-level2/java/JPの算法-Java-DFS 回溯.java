```
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root,sum,0,new ArrayList<Integer>());
        return ans;
    }
    //dfs+回溯
    public void dfs(TreeNode root,int target,int sum,List<Integer> list){
        if(root==null)
            return ;
        list.add(root.val);
        sum+=root.val;
        //叶子节点
        if(root.left==null&&root.right==null){
            if(sum==target)
                ans.add(new ArrayList(list));
            //回溯，删除最后一个
            list.remove(list.size()-1);
            return ;
        }
        dfs(root.left,target,sum,list);
        dfs(root.right,target,sum,list);
        list.remove(list.size()-1);
    }
}
```
