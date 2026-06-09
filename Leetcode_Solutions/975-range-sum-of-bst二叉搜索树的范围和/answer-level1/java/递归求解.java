### 解题思路
二叉搜索树:
- ·左子树的值小于根节点值
- ·右子树的值大于根节点值
判断根节点的值是否在这个范围，在的话返回root.val+左子树的范围和+右子树的范围和
若根节点的值大于R 右子树也不满足条件 直接返回右子树范围和
。。。
### 代码
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(null==root) return 0;
        if(root.val>R)
        return rangeSumBST(root.left,L,R);
        if(root.val<L)
        return rangeSumBST(root.right,L,R);
        
        return root.val+rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);
    }
}
```