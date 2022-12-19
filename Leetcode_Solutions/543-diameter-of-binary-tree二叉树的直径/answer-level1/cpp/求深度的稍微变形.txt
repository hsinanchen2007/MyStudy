这题目和求树深度差不多，不过遍历树的时候要记录两个量，深度和子树直径；然后更新子树直径
```
class Solution {
public:
    int x=0;
    int diameterOfBinaryTree(TreeNode* root) {
        depthOftree(root);
        return x;
    }
    int depthOftree( TreeNode* root){
        if(root==NULL) return 0;
        int left,right;
        if(root->left==NULL) left=0;
        if(root->right==NULL)  right=0;
        left=depthOftree(root->left);
        right=depthOftree(root->right);
        if(left+right>x) x=left+right;
        return max(left,right)+1;
    }
};
```
