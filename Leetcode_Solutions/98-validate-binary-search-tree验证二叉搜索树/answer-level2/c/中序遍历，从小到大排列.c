![image.png](https://pic.leetcode-cn.com/2af70a5f38c2173247e50c17a354cad5aedd1b9169cb47560b52170571515a4c-image.png)

bool track(struct TreeNode* root,int *lastVal, int *isFirstFlg)
{
    if (!root) return true;
    if (track(root->left, lastVal, isFirstFlg) == false) return false;
    if (root->val <= *lastVal && *isFirstFlg == 1)
    {
        return false;
    }
    *lastVal = root->val;
    *isFirstFlg = 1;
    if (track(root->right, lastVal, isFirstFlg) == false) return false;
    return true;
}

bool isValidBST(struct TreeNode* root) {
    int lastVal;
    int isFirstFlg = 0;
    return track(root, &lastVal, &isFirstFlg);
}