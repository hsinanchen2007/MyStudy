咋一看其实就是先序遍历，全部用right指针就好。
但用先序遍历修改指针后，势必让原本的右孩子找不到，必然要使用额外空间来记录。
但若采用后序遍历，倒着进行追溯，采用全局变量来存储刚刚访问过的节点，用本节点的right连接他即可！


```
class Solution {
    TreeNode temp;

    public void flatten(TreeNode root) {
        backOrder(root);
    }


    public void backOrder(TreeNode root){
        if(root == null)
            return ;
        
        backOrder(root.right);
        backOrder(root.left);

        root.right = temp;
        root.left = null;
        temp = root;

    }
    
}
```
