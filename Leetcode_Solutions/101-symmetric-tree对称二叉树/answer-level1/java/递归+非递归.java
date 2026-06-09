```
    /** 递归版本
    */
    public   boolean isSymmetric(TreeNode root) {
        if(root==null || (root.left==null && root.right==null) ){
            return true;
        }
        return digui(root.left,root.right);
    }

    public   boolean digui(TreeNode left,TreeNode right){
        if(left==null && right==null ) return true;
        if(left==null || right==null) return false;
        if(left.val != right.val ) return false;
        if((left.right==null && left.left==null)&&(right.left==null && right.right==null) && left.val==right.val) return true;
        return digui(left.right,right.left) && digui(left.left,right.right);
    }
```

```
    /**
     *  非递归版本
     *  基于BFS
     */
    public  static  boolean isSymmetric(TreeNode root) {
        if(root==null || (root.left==null && root.right==null) ){
            return true;
        }
        if(root.left==null|| root.right==null) return false;
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        queue.add(root.right);
        queue.add(root.left);
        while(!queue.isEmpty()){
            TreeNode first=queue.poll();
            TreeNode second=queue.poll();
            if(first.val!=second.val) return false;
            if(first.left==null && second.right!=null ||
                    first.left!=null && second.right==null ) return false;
            if(first.right!=null && second.left==null ||
                    first.right==null && second.left!=null ) return false;
            if(first.left!=null  && second.right!=null) {
                queue.add(first.left);
                queue.add(second.right);
            }
            if(first.right!=null && second.left!=null){
                queue.add(first.right);
                queue.add(second.left);
            }
        }
        return true;
    }
```

