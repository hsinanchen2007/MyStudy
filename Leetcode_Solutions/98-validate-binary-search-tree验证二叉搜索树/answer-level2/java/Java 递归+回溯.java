### 解题思路
为了验证二叉搜索树，我们任一节点的值大于其左子树的所有节点的值，小于其右子树所有节点的值。因此我们需要两个列表分别用来存放该节点的节点的值，必须大于该节点的节点的值。

### 代码

```java

class Solution {
    
    List<Integer> min=new ArrayList<>(),max=new ArrayList<>();
    
    boolean validate(TreeNode root){
        //如果是空节点或者叶子节点
        if(root==null||(root.left==null&&root.right==null))return true;
        //验证右儿子
        if(root.right!=null&&root.val>=root.right.val)
            return false;
        
        //验证左儿子
        if(root.left!=null&&root.val<=root.left.val)
            return false;
        
        //判断节点是否比右上方的都小
         for(int i:min)
                if((root.right!=null&&i>=root.right.val)||(root.left!=null&&i>=root.left.val))
                    return false;
        
        //判断节点是否比左上方的都大
         for(int i:max)
                if((root.right!=null&&i<=root.right.val)||(root.left!=null&&i<=root.left.val))
                    return false;
        
        boolean res=true;
        
        //如果有左子树，则把当前节点加入max列表，表示当前节点左子树的所有节点的值必须比当前节点的小
        if(root.left!=null){
            max.add(root.val);
            res=res&&validate(root.left);
            //移除当前节点
            max.remove(max.size()-1);
        }
        
        //如果有右子树，则把当前节点加入min列表，表示当前节点右子树的所有节点的值必须比当前节点的大
        if(root.right!=null){
            min.add(root.val);
            res=res&&validate(root.right);
            min.remove(min.size()-1);
        }

        return res;
    }
    
    public boolean isValidBST(TreeNode root) {
        return validate(root);
    }
}
```