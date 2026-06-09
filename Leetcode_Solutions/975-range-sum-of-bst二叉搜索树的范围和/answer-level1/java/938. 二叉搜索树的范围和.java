中序遍历：
若节点值大于等于L, 且小于等于R, 将该节点的值累加到sum上。
```
class Solution {
    int sum=0;
    public int rangeSumBST(TreeNode root, int L, int R) {
        inOrder(root, L, R);
        return sum;
    }
    public void inOrder(TreeNode root,int L,int R){
        if(root==null){
            return;
        }
        inOrder(root.left,L,R);
        if(root.val>=L&&root.val<=R){
            sum+=root.val;
        }
        inOrder(root.right,L,R);
    }
}
```
