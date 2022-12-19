```
void findSecond(struct TreeNode* root, int *m){
    if (!root)
        return ;
    else
    {
        if (m[1] != -1 && root->val > m[0] && root->val < m[1])  // 会一直往上找
        {
            m[1] = root->val;
        }
        else if (m[1] == -1 && root->val > m[0])
            m[1] = root->val;
        findSecond(root->left, m);
        findSecond(root->right, m);
    }
}


int findSecondMinimumValue(struct TreeNode* root){
    int *m = malloc(sizeof(int) * 2);
    if (!root)
        return -1;
    else
    {
        m[0] = root->val;
        m[1] = -1;
    }
    findSecond(root, m);
    return m[1];
}
```
