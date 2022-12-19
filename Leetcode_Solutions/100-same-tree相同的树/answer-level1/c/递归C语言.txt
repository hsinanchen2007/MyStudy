/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isEqual = true;

bool Dfs(struct TreeNode* p, struct TreeNode* q)
{
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        isEqual = false;
        return false;
    }

    if (p == NULL && q == NULL) {
        return true;
    }

    if ((p != NULL && q != NULL) && (p->val != q->val)) {
        isEqual = false;
        return false;
    }

    if (p != NULL && q != NULL) {
        Dfs(p->left, q->left);
        Dfs(p->right, q->right);
    }

    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    isEqual = true;

    if (p == NULL && q == NULL) {
        return true;
    }

    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
    }

    Dfs(p, q);

    return isEqual;
}

![image.png](https://pic.leetcode-cn.com/9f132fa2dcf0c2b51e2f6ae6da95b161c09618acb9b2f64c7703e5fa35b86e2a-image.png)
