class Solution {
    public boolean verifyPostorder(int[] postorder) {
        //二叉搜索树中序遍历是 有序数组
        if(postorder==null)
            return false;
        if(postorder.length==1)
            return true;
        return ju(postorder,0,postorder.length-1);

    }

    public boolean ju(int[] a,int star,int root){
        //递归停止条件
        if(star>=root)
            return true;
        //从后面开始找
        int i=root;
        while(i>star&&a[i-1]>a[root]){
            i--;
        }
        //从前面开始找 star到i-1应该比根小
        for(int j = star;j<i-1;j++)
            if(a[j]>a[root])
                return false;
        return ju(a,star,i-1)&&ju(a, i, root-1);


    }
}