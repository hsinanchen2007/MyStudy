中序遍历，递增则为二叉搜索树。
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        List<Integer> li =new ArrayList<>();
        inOrder(root,li);
        if(li.size()==0){
            return true;
        }else{
            for(int i=0;i<li.size()-1;i++){
                int j = i+1;
                if(li.get(i)>=li.get(j)){
                    return false;
                }
            }
            return true;
        }
    }

    public void inOrder(TreeNode root ,List<Integer> ls){
        if(root== null){
            return ;
        }
        if(root.left!=null){
            inOrder(root.left,ls);
        }
        ls.add(root.val);
        if(root.right!=null){
            inOrder(root.right,ls);
        }

    }

    
}
```
