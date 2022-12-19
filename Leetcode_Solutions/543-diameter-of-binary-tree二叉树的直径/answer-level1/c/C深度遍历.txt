不知道有什么方法可以不写子函数，在主函数里递归
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTreeIter(struct TreeNode*, int*);
int max(int, int);

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 1;
    diameterOfBinaryTreeIter(root, &ans);
    return ans -1;
}

int diameterOfBinaryTreeIter(struct TreeNode* root, int* ans_p){
    if (!root) return 0;
    int L = diameterOfBinaryTreeIter(root->left, ans_p);
    int R = diameterOfBinaryTreeIter(root->right, ans_p);
    *ans_p = max(*ans_p, L + R + 1);
    return max(L, R) + 1;
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}
```
