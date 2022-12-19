```
class Solution {
    List<Integer> list = new ArrayList<>();
    public boolean isValidBST(TreeNode root) {
         if(root == null){
             return true;
         }
         return isValidBSTHelper(root);
    }
    public boolean isValidBSTHelper(TreeNode root){
            if(root == null)
                return true;
            //本质就是中序遍历嘛，左根右边，保证有序即可
            return isValidBSTHelper(root.left)&&sorted(root.val)&&isValidBSTHelper(root.right);
    }

    public boolean sorted(int val){
        if(list.size() == 0 || val>list.get(list.size()-1)){
            list.add(val);
            return true;
        }else
            return false;
    }
}
```
