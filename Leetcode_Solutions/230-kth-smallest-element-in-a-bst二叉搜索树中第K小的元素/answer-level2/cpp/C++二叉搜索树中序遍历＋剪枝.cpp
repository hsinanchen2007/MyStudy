时间、空间击败90%+
```
class Solution {
private:
    void p(TreeNode *root, int k, int &res, int &size){
        if(root){
            p(root->left, k, res, size);
            size++;
            if(size == k){
                res = root->val;
                return;
            }
            p(root->right, k, res, size);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res, size = 0;
        p(root, k, res, size);
        return res;
    }
};
```
