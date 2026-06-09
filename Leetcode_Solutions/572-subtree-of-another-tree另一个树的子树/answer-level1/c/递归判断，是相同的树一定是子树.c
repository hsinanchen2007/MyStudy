/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSametree(struct TreeNode* s, struct TreeNode* t)
{
    if((s == NULL)&&(t == NULL))
        return true;
    if((s == NULL)||(t == NULL))
        return false;
    if(s->val == t->val)
        return isSametree(s->left, t->left) && isSametree(s->right, t->right);
    else
        return false;
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL)
        return false;
    else
        return isSametree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}