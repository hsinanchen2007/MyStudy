```
 /*
    思路：二叉搜索树 则根据中序遍历，左根右，设置一个计数的，每次访问一个就减一，若为0，则返回该节点对应值

    总结：k--和if判断相当于对根节点进行访问
 */
class Solution {
    int k =0;
    int temp = 0;
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        helper(root);
        return temp;
    }
    public void helper(TreeNode root)
    {
        if(root.left!=null) helper(root.left);
        k--;
        if(k==0) 
        {
            temp = root.val;
            return;
        }
        if(root.right!=null) helper(root.right);
    }
}
```
