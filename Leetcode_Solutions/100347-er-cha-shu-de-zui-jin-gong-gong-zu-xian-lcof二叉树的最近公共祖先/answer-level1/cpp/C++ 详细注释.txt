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
    // 遍历左子树，如果只找到一个，那么当前就是该返回的值, 一个没找到，那么去右子树，如果找到两个，往左子树遍历
    // 如果root等于某一个值，返回root
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val)
            return root;
        int num=0;
        helper(num, root->left, p, q); // 遍历左子树
        if(num==1)
            return root;
        if(num==2)
            return lowestCommonAncestor(root->left, p, q);
        if(num==0)
            return lowestCommonAncestor(root->right, p, q);
        return NULL;
    }
    void helper(int& num, TreeNode* root, TreeNode* p, TreeNode* q){
        // 前序遍历
        if(!root)
            return;  //空  返回
        if(root->val==p->val || root->val==q->val)
            num++;  // 先遍历根节点
        helper(num, root->left, p, q); // 左子树
        helper(num, root->right, p, q); // 右子树     
    }
};