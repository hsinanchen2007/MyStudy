### 解题思路
dfs

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        vector<int> item;
        helper(res, item, root, 0, sum);
        return res;
    }

    void helper(vector<vector<int> >& res, vector<int>& item, TreeNode* node, int current, int sum) {
        item.push_back(node->val);
        current = current + node->val;
        if(node->left == NULL && node->right == NULL) {
            if (current == sum) {
                res.push_back(item);
                //return;
            } 
        }

        if (node->left != NULL) {
            helper(res, item, node->left, current, sum);
        }
        if (node->right != NULL) {
            helper(res, item, node->right, current, sum);
        }
        item.pop_back();
    }
};
```