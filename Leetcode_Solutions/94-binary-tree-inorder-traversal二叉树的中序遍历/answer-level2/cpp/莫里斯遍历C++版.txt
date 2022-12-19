```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* p = curr->left;
                while(p->right)
                    p = p->right;//左子树中的最右侧结点
                p->right = curr;//将curr设置为最右侧结点的右结点
                TreeNode* tmp = curr;
                curr = curr->left;//进入左子树
                tmp->left = NULL;//将原curr的左子树置空
            }
        }
        return res;
    }
};
```

