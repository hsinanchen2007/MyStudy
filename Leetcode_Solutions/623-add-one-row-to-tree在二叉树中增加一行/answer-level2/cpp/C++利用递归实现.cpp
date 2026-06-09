直接利用递归莽就完事了,需要注意的是要注意当d=1时,应该将根节点加到新节点的左侧,而这一点题目并没有明确地给出
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root == NULL){
            return NULL;
        }
        if(d==1){
            TreeNode *temp = new TreeNode(v);
            temp->left = root;
            temp->right = NULL;
            return temp;
        }
        if(d==2){
            TreeNode *templ = new TreeNode(v);
            templ->left = root->left;
            templ->right = NULL;
            root->left = templ;

            TreeNode *tempr = new TreeNode(v);
            tempr->left = NULL;
            tempr->right = root->right;
            root->right = tempr;
            return root;
        }
        addOneRow(root->left,v,d-1);
        addOneRow(root->right,v,d-1);
        return root;
    }
};