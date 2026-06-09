思路如下：前序遍历的第一个数是根节点，并且该数在中序遍历中可以将树分为左右两子树。如例子中的
前序遍历 preorder = [3,9,20,15,7] 中序遍历 inorder = [9,3,15,20,7] 其中3 将inorder分为[9]和[15,20,7]左右子树。
那么只需要记录下左右子树有哪些，再在各个子树中去寻找根节点，即前序遍历 preorder 的下一个数的值，即可。



```
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        LinkedList<Integer> childleftlist=new LinkedList<Integer>();
        LinkedList<Integer> childrightlist=new LinkedList<Integer>();
        TreeNode root=new TreeNode(preorder[0]);
        boolean left=true;
        //分别构建左右子树，添加节点进入子树
        for (int i = 0; i < inorder.length; i++) {
            if(inorder[i]==preorder[0])left=false;
            else {
                if(left)childleftlist.add(inorder[i]);
                else childrightlist.add(inorder[i]);
            }
        }
        buildleft(root,preorder,1,childleftlist,childrightlist);
        return root;
    }

    private void buildleft(TreeNode root,int[] preorder,int i,LinkedList<Integer> leftlist,LinkedList<Integer>rightlist) {
        //构建该节点的孩子左右子树
        LinkedList<Integer> childleftlist=new LinkedList<Integer>();
        LinkedList<Integer> childrightlist=new LinkedList<Integer>();
        //记录preorder在左子树下的根节点
        int lefti=i;
        boolean left=true;
        if(!leftlist.isEmpty()) {
            while (!leftlist.isEmpty()) {
                int temp = leftlist.removeFirst();
                if (temp == preorder[lefti]) {
                    root.left = new TreeNode(temp);
                    left = false;
                } else {
                    //若不等，说明该节点存在左或者右子树，添加进左右子树中
                    if (left) childleftlist.add(temp);
                    else childrightlist.add(temp);
                }
                i++;//为了记录左子树的长度以便后续得到右子树的根节点在preorder中的位置
            }
            buildleft(root.left,preorder,lefti+1,childleftlist,childrightlist);
        }
        if(!rightlist.isEmpty()){
            //此时i指向的是 [3,9,20,15,7]中的20，即右子树根节点
            childleftlist.clear();childrightlist.clear();
            left=true;
            while (!rightlist.isEmpty()){
                int temp=rightlist.removeFirst();
                if(temp==preorder[i]){
                    root.right=new TreeNode(temp);
                    left=false;
                }else {
                    if (left) childleftlist.add(temp);
                    else childrightlist.add(temp);
                }
            }
            buildleft(root.right,preorder,i+1,childleftlist,childrightlist);
        }
    }
```
