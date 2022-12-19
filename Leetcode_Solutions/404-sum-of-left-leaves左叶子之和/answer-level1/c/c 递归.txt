int sum = 0;

void sumLeftLeave(struct TreeNode* root, int isleft)
{
    if (!root) return;
    if (!root->left && !root->right && isleft) {
        sum += root->val;
        return;
    }
    sumLeftLeave(root->left,1);
    sumLeftLeave(root->right,0);
}

int sumOfLeftLeaves(struct TreeNode* root){
    sum = 0;
    if (!root) return 0;

    sumLeftLeave(root->left,1);
    sumLeftLeave(root->right,0);
    return sum;

}