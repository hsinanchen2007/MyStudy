```
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* node = new TreeNode(0);
        dfs(t1, t2, &(node));
        return node;
    }
    void dfs(TreeNode* t1, TreeNode* t2, TreeNode **root){
        if (t1 && t2) {
            *root = new TreeNode(t1->val + t2->val);
        }else if (t1) {
            *root = new TreeNode(t1->val);
        }else if (t2) {
            *root = new TreeNode(t2->val);
        }else{
            *root = nullptr;
            return;
        }
        TreeNode *left1 = t1 ? t1->left : nullptr;
        TreeNode *left2 = t2 ? t2->left : nullptr;
        dfs(left1, left2, &((*root)->left));
        
        TreeNode *right1 = t1 ? t1->right : nullptr;
        TreeNode *right2 = t2 ? t2->right : nullptr;
        dfs(right1, right2,  &((*root)->right));
    }
}
```
// DFS递归调用，当时使用指针来修改值调了很久，指针用的太差了。
