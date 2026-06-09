### 解题思路

### 代码
判断`root`是否是平衡树，就要求出其左右子树的最大高度，然后相减得出高度差，大于等于2的必然不是平衡树。
所以，求高度的递归函数`deep()`参数树根,返回深度，再引入一个全局标志位`balance`，代表是否平衡，但凡有某个子树出现不平衡，那就不用继续了。
以下为递归步骤：
1. 如果全局标志`balance==false||root==null`，返回0;
2. 求出左子树高度`ll=deep(root.left);lr=deep(root.right);`
3. 如果`|ll-lr|>=2`,`balance`置`false`，且返回0;
4. 返回`ll`与`lr`的最大值+1;
```java
class Solution {

    private boolean balance=true;
    private int deep(TreeNode root)
    {
        if(root==null||!balance)return 0;

        int ll=deep(root.left);
        int lr=deep(root.right);

        if(Math.abs(ll-lr)>=2)
        {
            balance=false;
            return 0;
        }
        return Math.max(ll,lr)+1;
    }
    public boolean isBalanced(TreeNode root) {
        deep(root);
        return balance;
    }
}
```