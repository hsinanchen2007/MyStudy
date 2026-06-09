### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr) return vector<vector<string>>();
        int height = max_depth(root);
        int width = search_length(root);
        vector<vector<string>> mat(height, vector<string>(width, ""));
        fill_tree(root, mat, 0, width-1, 0);
        return mat;
    }

    void fill_tree(TreeNode *p, vector<vector<string>> &mat, int left, int right, int level){
        if(p == nullptr) return;
        int mid = left + (right-left) / 2;
        mat[level][mid] = to_string(p->val);
        fill_tree(p->left, mat, left, mid-1, level+1);
        fill_tree(p->right, mat, mid+1, right, level+1);
    }

    int max_depth(TreeNode *p){
        if(p == nullptr) return 0;
        int left = max_depth(p->left);
        int right = max_depth(p->right);
        return max(left, right)+1;
    }

    int search_length(TreeNode *p){
        if(p == nullptr) return 1;
        if(p->left == nullptr && p->right == nullptr) return 1;
        int left = search_length(p->left);
        int right = search_length(p->right);
        return 2*(max(left, right)) + 1;
    }
};
```