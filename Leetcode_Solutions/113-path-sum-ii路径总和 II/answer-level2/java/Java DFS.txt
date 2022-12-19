***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，持续更新。***

思路和上个题类似，只是递归时加入了List来储存当前路径元素，注意每次递归完需要将list中的当前元素值删除。其实就是DFS+回溯

```
public List<List<Integer>> pathSum(TreeNode root, int sum) {
    List<List<Integer>> res = new ArrayList<>();
    if(root == null) return res;
    helper(root,sum,new ArrayList<>(),res);
    return res;
}

private void helper(TreeNode root, int sum, List<Integer> list, List<List<Integer>> res) {
    if(root == null) return;
    list.add(root.val);
    if(root.left == null && root.right == null && sum == root.val){
        res.add(new ArrayList<>(list));
    }
    helper(root.left,sum-root.val,list,res);
    helper(root.right,sum-root.val,list,res);
    //回退
    list.remove(list.size()-1);
}
```
