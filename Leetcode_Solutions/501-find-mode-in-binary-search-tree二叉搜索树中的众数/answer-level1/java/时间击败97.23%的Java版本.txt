执行用时 : 2 ms, 在Find Mode in Binary Search Tree的Java提交中击败了97.23% 的用户   
内存消耗 : 41.4 MB, 在Find Mode in Binary Search Tree的Java提交中击败了60.51% 的用户  
```
class Solution {
    List<Integer> list = new ArrayList<>();
    TreeNode pre;
    int max = 0;
    int cur = 1;
    public int[] findMode(TreeNode root) {
        if(root==null) {
            return new int[] {};
        }
        inorder(root);
        int[] a = new int[list.size()];
        for(int i=0;i<list.size();i++) {
            a[i]=list.get(i);
        }
        return a;
    }
    private void inorder(TreeNode root) {
        if(root==null) {
            return ;
        }
        inorder(root.left);
        if(pre!=null) {
            if(pre.val==root.val) {
                cur++;
            }
            else {
                cur=1;
            }
        }
        if(cur==max) {
            list.add(root.val);
        }
        if(cur>max) {
            list.clear();
            list.add(root.val);
            max=cur;
        }
        pre=root;
        inorder(root.right);
    }
}
```