执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :37.8 MB, 在所有 java 提交中击败了79.08%的用户
```
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> AL = new ArrayList();
        if(root == null)
            return AL;
        List<Integer> list = new ArrayList();
        getResult(root, AL, list, sum);
        return AL;
    }
    public void getResult(TreeNode root, List<List<Integer>> AL, List<Integer> list, int sum){
        list.add(root.val);
        if(root.left == null && root.right == null){
            if(sum-root.val == 0)
                AL.add(new ArrayList(list));
            list.remove(list.size()-1);
            return;
        }
        if(root.left != null)
            getResult(root.left, AL, list, sum-root.val);
        if(root.right != null)
            getResult(root.right, AL, list, sum-root.val);
        list.remove(list.size()-1);
    }
}
```
