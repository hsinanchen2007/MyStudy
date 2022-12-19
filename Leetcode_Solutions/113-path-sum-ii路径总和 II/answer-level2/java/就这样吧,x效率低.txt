```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if(root == null)
            return lists;
        List<Integer> list = new ArrayList<>();
        pathSum(root,sum,list);
        return lists;
    }

    public void pathSum(TreeNode root,int sum,List<Integer> list){
         if(root == null){
             return;
         }
          list.add(root.val);
          //叶子
         if(root.left==null&&root.right==null&&sum==root.val){
             lists.add(list);
         }
         pathSum(root.left,sum-root.val,new ArrayList<Integer>(list));
         pathSum(root.right,sum-root.val,new ArrayList<Integer>(list));
    }
}
```
