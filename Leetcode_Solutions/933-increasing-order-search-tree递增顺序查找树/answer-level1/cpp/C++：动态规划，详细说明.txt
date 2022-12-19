```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 原来的函数
    TreeNode* increasingBST(TreeNode* root) {
        return  increasingBST(root,NULL);
    }
    
    // 重载为两个参数
    TreeNode* increasingBST(TreeNode* root,TreeNode* next){
        // 如果当前root为空树，直接返回NULL
        if(root==NULL) 
            return NULL;
        
        // 动态规划：对当前root节点，先处理右子树，再处理左子树
        if(root->right==NULL) 
            // 如果当前root没有右子树，直接将next作为其右子树（的根）
            root->right = next;
        else 
            // 如果当前root有右子树，则把右子树中的最左节点作为其右子树（的根）
            root->right = increasingBST(root->right,next);
        // 如果处理完右子树，发现没有左子树（即当前root不用作为谁的下一个节点），则直接返回root
        if(root->left==NULL) 
            return root;
        // 如果有左子树，则把当前root作为其左子树的（最右节点的）下一个节点
        next = root;
        // 以当前root作为其左子树的下一个节点，处理左子树
        TreeNode* ans = increasingBST(root->left,next);
        // 当前root的左右子树都处理完后，形成一条右树连（每个节点最多只有右子树），将当前root节点的左子树置为空
        root->left = NULL;

        return ans;
    }
};
```