# 解题思路

- 错误思路
    - 认为 最大高度是 根节点的左子树的高度和右子树的高度和
- 正确思路
    - 计算每一个节点的对应树的 直径 并维护一个max值 
        - 维护max值可以 放在求子树height的时候进行
    - 最后返回max值
    - 

```

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int max = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        getHeight(root);
       return max;
    }
    public int getHeight(TreeNode root){
        if(root == null)
            return 0;
        int l = getHeight(root.left);
        int r = getHeight(root.right);
        max = Math.max(max,l+r);
        return Math.max(l,r)+1;
    }
}

}
```
