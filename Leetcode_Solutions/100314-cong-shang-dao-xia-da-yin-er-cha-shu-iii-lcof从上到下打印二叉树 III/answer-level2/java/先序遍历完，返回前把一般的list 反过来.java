```
class Solution {
    List<List<Integer>> ref;
    public List<List<Integer>> levelOrder(TreeNode root) {
        ref = new ArrayList<>();
        if(root == null) {
            return ref;
        }
        helper(root, 0);
        for(int i = 1; i < ref.size(); i += 2) {
            Collections.reverse(ref.get(i));
        }
        return ref;
    }   
    private void helper(TreeNode root, int cnt) {
        if(root == null) {
            return;
        }
        if(ref.size() <= cnt) {
            ref.add(new ArrayList<>());
        }
        ref.get(cnt).add(root.val);
        helper(root.left, cnt + 1);
        helper(root.right, cnt + 1);
    }
}
```
