### 解题思路
这是由下到上的递归处理思路。
`private void adjust(TreeNode root)`处理思路:
1. 将`root`的左右子树调换位置;
2. 对`root.left`进行`adjust`递归
3. 对`root.right`进行`adjust`递归
4. 如果`root`的左子树不为空，那么执行以下操作
   - 找到`root`的右子树的最底层及最右节点`iter`
   - 令`iter`的右子树为`root`的左子树。即`iter.right=root.left;`
### 代码

```java
class Solution {
    
    private void swapTreeNode(TreeNode root)//swap root.left &root.right
    {
        TreeNode temp=root.left;
        root.left=root.right;
        root.right=temp;
    }
    private void adjust(TreeNode root)
    {
        if(root==null)return;
        
        swapTreeNode(root);
        
        adjust(root.left);
        adjust(root.right);
        
        if(root.left!=null)
        {
            TreeNode iter=root;
            while(iter.right!=null)
                iter=iter.right;
            iter.right=root.left;
            root.left=null;
        }

    }
    public void flatten(TreeNode root) {
        adjust(root);
    }
}
```