### 解题思路
1、判断边界条件。
1）root为NULL，直接返回。
2）root左右子树为空，并且sum满足条件，存放结果。
2、递归左右子树。
注意点：每次cur在push_back的之后都应该对应一个pop_back().

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
private:
    vector<vector<int>> res;
    vector<int> cur;
public:
    void DFS(TreeNode* root, int sum, int k){
        if(!root){
            return;
        }
        if(!root->left && !root->right && root->val + k == sum){
            cur.push_back(root->val);
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        DFS(root->left, sum, k+ root->val);
        DFS(root->right, sum, k+root->val);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        DFS(root, sum, 0);
        return res;
    }
};
```