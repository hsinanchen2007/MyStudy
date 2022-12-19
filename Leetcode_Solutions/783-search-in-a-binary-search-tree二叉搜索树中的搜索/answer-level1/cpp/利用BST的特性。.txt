# 普通解
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        auto l = searchBST(root->left, val);
        auto r = searchBST(root->right, val);
        if(l)return l;
        if(r)return r;
        return NULL;
    }
};
```
显然普通解与这棵树是不是BST并无关系，但既然是BST，那么就从根结点遍历，并且根据`root->val > = < val`进行二分，提高效率。
# 二分搜索
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left, val);
        else if(root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};
```