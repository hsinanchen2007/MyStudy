本小白只想到傻瓜方法，先利用中序遍历将各个结点存储到List中，然后顺序遍历List中的元素改变指针指向，就是这样不知道算不算是原地修改啊。
```
private void midTrace(TreeNode root){
        if (root==null) return;
        TreeNode h=root;
        list.add(h);
        midTrace(h.left);
        midTrace(h.right);
    }
    public void flatten(TreeNode root) {
        if (root==null) return;
        midTrace(root);
        for (int i=0;i<list.size()-1;i++){
            list.get(i).left=null;
            list.get(i).right=list.get(i+1);
        }
        list.get(list.size()-1).left=null;
        list.get(list.size()-1).right=null;
        return;
    }
```
