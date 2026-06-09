* leetcode很多题都是一样的，我记得有一道是有序数组转换成二叉树，可以找找，思路是一样的
* 这道题只要知道中序遍历能将搜索树有序遍历
* 然后会将有序集合转换为二叉树就完成了
```java
class Solution {
    List<TreeNode> temp=new ArrayList();
    public TreeNode balanceBST(TreeNode root) {
        add(root);
        return make(temp,0,temp.size()-1);
    }
    //中序遍历add
    private void add(TreeNode root){
        if (root==null) return;
        add(root.left);
        temp.add(root);
        add(root.right);
    }
    //重构二叉树
    private TreeNode make(List<TreeNode> temp,int left,int right){
        if (left>right) return null;
        int mid=(left+right)/2;
        TreeNode res=temp.get(mid);
        res.left=make(temp,left,mid-1);
        res.right=make(temp,mid+1,right);
        return res;
    }
}
```