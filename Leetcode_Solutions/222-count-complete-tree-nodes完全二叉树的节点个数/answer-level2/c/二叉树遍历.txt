int g_NodeNum = 0;

void myCountNodes(struct TreeNode* root){
    if (0==root){
        return;
    }
    g_NodeNum++;
    if (root->left == 0){
        return;
    }
    myCountNodes(root->left);
    myCountNodes(root->right);
    return;
}

int countNodes(struct TreeNode* root){
    g_NodeNum = 0;
    myCountNodes(root);
    return g_NodeNum;
}