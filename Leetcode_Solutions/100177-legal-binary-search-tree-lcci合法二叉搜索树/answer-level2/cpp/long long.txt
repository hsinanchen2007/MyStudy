### 解题思路
此处撰写解题思路

### 代码
```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        auto res=helper(root);
        return res[0];
    }

    vector<long long> helper(TreeNode* root){
        if(!root) return {true,LLONG_MAX,LLONG_MIN};

        auto left=helper(root->left);
        auto right=helper(root->right);

        if(!left[0] || !right[0] || root->val<=left[2] || root->val>=right[1]) return {false,0,0};//判断是否符合要求

        int curmin= root->left==NULL?root->val:left[1];
        int curmax= root->right==NULL?root->val:right[2];

        return {true,curmin,curmax};
    }
};
```