
```
class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> list = new ArrayList<Integer>();
        visit(root1, list);
        visit(root2, list);
        Collections.sort(list);
        return list;
    }
    
    public void visit(TreeNode root, List<Integer> list) {
        if (root!=null) {
            list.add(root.val);
            visit(root.left, list);
            visit(root.right, list);
        }
    }
}
```
