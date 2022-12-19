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
    //使用范围，记录左右子树的最小值和最大值
    bool dfs(TreeNode* root, long long minv, long long maxv) {
        if(!root) {
            return true;
        }
        if(root->val < minv || root->val > maxv) {
            return false;
        }
        return dfs(root->left, minv, root->val-(long long)1)
            && dfs(root->right, root->val+(long long)1, maxv);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
```
2.验证中序遍历序列是否为单调增
```
class Solution {
    vector<int> v;
    void inorder_traverse(TreeNode* root) {
        if (root->left) {
            inorder_traverse(root->left);
        }        
        v.pushback(root->val);
        if (root->right) {
            inorder_traverse(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        v.clear();
        inorder_traverse(root);
        for(int i = 0; i < v.size()-1; i++) {
            if(v[i] >= v[i+1]) {
                return false;
            }
        }
        return true;        
    }
};
```
