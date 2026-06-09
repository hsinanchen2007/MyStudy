```
class Solution {
    List<List<Integer>> ans=new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root==null){
            return ans;
        }
        backTracing(root,sum,new ArrayList<Integer>());
        return ans;
    }
    public void backTracing(TreeNode root, int sum,List<Integer> list){
        if(root==null){
            return ;
        }
        sum-=root.val;
        list.add(root.val);
        if(sum==0&&root.left==null&&root.right==null){
            ans.add(new ArrayList<Integer>(list));
        }else{
            backTracing(root.left,sum,new ArrayList<Integer> (list));
            backTracing(root.right,sum,new ArrayList<Integer>(list));
        }
        list.remove(list.size()-1);
    }
}
```
