```
class Solution {
    /*
    执行用时 :3 ms, 在所有 Java 提交中击败了92.88%的用户
    内存消耗 :38.2 MB, 在所有 Java 提交中击败了69.73%的用户
    */
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        if(root == null) return res;
        generate(res,new ArrayList<>(), root,sum);
        return res;
    }
    private void generate( List<List<Integer>> res, List<Integer> list, TreeNode root, int sum) {
        if(root == null) {return;}
        if(root.left == null && root.right == null && sum == root.val) {
            list.add(root.val);
            res.add(new ArrayList<>(list));
            list.remove(list.size()-1);
            return;
        }
        else {
            list.add(root.val);
            generate(res,list,root.left,sum-root.val);
            generate(res,list,root.right,sum-root.val);
            list.remove(list.size()-1);
        }
    }
}
```
