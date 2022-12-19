```
class Solution {
    List<List<Integer>> ans=new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
      backtrack(root,sum,new ArrayList<>());
          return ans;
    }
    public void backtrack(TreeNode root,int sum,ArrayList<Integer> path){
            if(root==null)
                return;
     path.add(root.val);
        sum-=root.val;
        if(sum==0&&root.left==null&&root.right==null)
            ans.add(new ArrayList<>(path));
        else
           {
            backtrack(root.left,sum,path);
            backtrack(root.right,sum,path);
            }
        path.remove(path.size()-1);
    }
}
```
