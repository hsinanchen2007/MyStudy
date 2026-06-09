```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> order;
        sort(root,order);
        bool ret = true;
        for (int i=0;i<order.size()-1;i++) {
            if (order[i]>=order[i+1]) {
                ret = false;
                break;
            }
        }
        return ret;

    }

    void sort(TreeNode* root,vector<int> &vec) {
        if (root == NULL) return;
        sort(root->left,vec);
        vec.push_back(root->val);
        sort(root->right,vec);
    }
};
```
