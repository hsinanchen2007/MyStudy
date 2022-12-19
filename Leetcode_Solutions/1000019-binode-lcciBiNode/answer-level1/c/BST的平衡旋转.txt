```
struct TreeNode* RR(struct TreeNode* cur)
{
    struct TreeNode* tmp = cur->left;
    cur->left = tmp->right;
    tmp->right = cur;
    return tmp;
}

struct TreeNode* convertBiNode(struct TreeNode* root){
    struct TreeNode head;
    head.right = root;
    head.left = NULL;
    struct TreeNode* tmp = &head;
    while(tmp != NULL) {
        while (tmp->right != NULL && tmp->right->left != NULL) {
            tmp->right = RR(tmp->right);
        }
        tmp = tmp->right;
    }
    return head.right;
}
```
