### 解题思路

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max = 0;
int depth(struct TreeNode* root){
    int l = 0, r = 0;

    if (root == NULL)
        return 0;
    l = depth(root->left);
    r = depth(root->right);

    max = max > (l + r) ? max : (l + r);
    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root){
    max = 0;

    depth(root);
    return max; 
}
```