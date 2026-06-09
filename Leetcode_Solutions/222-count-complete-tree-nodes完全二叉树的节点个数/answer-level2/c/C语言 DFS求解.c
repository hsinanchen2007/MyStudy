/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root, int* count){
    if (root){
        *count = *count + 1;
        dfs(root->left,count);//把指针传进去
        dfs(root->right,count);
    }
}

int countNodes(struct TreeNode* root){
    //递归，深度优先
    int count = 0;
    dfs(root,&count);

    return count;
}