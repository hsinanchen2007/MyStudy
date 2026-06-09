```
class Solution {
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if (t1==null || t2==null) return t2==null;
        StringBuilder s_1 = new StringBuilder();
        doSerialize(t1,s_1);
        StringBuilder s_2 = new StringBuilder();
        doSerialize(t2,s_2);
        return s_1.toString().indexOf(s_2.toString())>-1;
    }
    private void doSerialize(TreeNode root,StringBuilder sb){
        if (root!=null){
            sb.append(root.val+"_");
            doSerialize(root.left,sb);
            doSerialize(root.right,sb);
        }else
            sb.append("#_");
            
    }
}
```
