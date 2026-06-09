先深搜，然后通过返回叶子结点的值进行判断是否要将子节点设置为null，然后一直递归返回就完成了
```
    public TreeNode removeLeafNodes(TreeNode root, int target) {
    int k = remove(root, target);
    if(k==target)
        return null;
    else
        return root;
    }
    public int remove(TreeNode root,int target){
      if(root.left!=null){
         int t =  remove(root.left,target);
         if(t!=-1){
         if(t==target)
             root.left = null;
      }
      }
      if(root.right!=null){
         int t= remove(root.right,target);
         if(t!=-1){
         if(t==target)
             root.right = null;
      }
      }
      if(root.right==null&&root.left==null){
            return root.val;
        }
      return -1;
      }


```
