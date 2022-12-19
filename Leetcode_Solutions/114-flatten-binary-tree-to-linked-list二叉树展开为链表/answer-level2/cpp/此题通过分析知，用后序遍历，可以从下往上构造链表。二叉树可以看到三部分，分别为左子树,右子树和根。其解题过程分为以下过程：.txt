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
    void flatten(TreeNode* root) {
        if(root == NULL) 
            return ;
        //采用后续遍历的方法
        if(root->left != NULL)
            flatten(root->left);
        if(root->right != NULL)
            flatten(root->right);
        if(root->left != NULL) {                //如果root->left不等于NULL，就用root->left的最后的右孩子，指向                      root->right
            TreeNode* pNode = root->left;
            while(pNode->right != NULL)
                pNode = pNode->right;
            pNode->right = root->right;
        }            
        else                                    //如果root->left为NULL，就用root->right存储在root->left中
            root->left = root->right;
        root->right = root->left;               //root的后继节点为root的右孩子
        root->left = NULL;                      //将遍历到的每个节点的左孩子设为NULL

    }
};