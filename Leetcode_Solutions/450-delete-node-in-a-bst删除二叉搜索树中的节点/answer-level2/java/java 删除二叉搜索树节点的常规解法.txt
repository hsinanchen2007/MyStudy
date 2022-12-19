```
public TreeNode deleteNode(TreeNode root, int key) {
        //当前节点
        TreeNode p = root;
        //当前节点的父节点
        TreeNode pp = null;
        while(p!=null && key!=p.val) {
            pp=p;
            if(key>p.val) {
                p=p.right;
            }else {
                p=p.left;
            }
        }
        /**
         * 没有找到
         */
        if(p==null) {
            return root;
        }
        
        /**
         * 如果要删除的节点，左，右子节点都有值
         * 找到右子节点中的最小值
         */
        while(p.left!=null && p.right!=null) {
            TreeNode minP =p.right;
            TreeNode minPP =p;
            while(minP.left!=null) {
                minPP=minP;
                minP=minP.left;
            }
            /**
             * 找到最小值，肯定没有左子节点
             */
            p.val=minP.val;
            //再次赋值，标记为一个没有左节点
            p=minP;
            pp=minPP;
        }
        
        /**
         * 如果要删除的节点只有一个左子节点，或者右子节点，或者没有子节点
         */
        TreeNode child=null;
        if(p.left!=null) {
            //右边是空
            child=p.left;
        }else if(p.right!=null) {
            //左边是空
            child=p.right;
        }else {
            //没有左，右子节点
            child=null;
        }
        
        /**
         * 改变，要删除节点的父节点的指向
         */
        if(pp==null) {
            //要删除的是根节占
            root=child;
        }else if(pp.left==p) {
            pp.left=child;
        }else {
            pp.right=child;
        }
        return root;
    }
```
