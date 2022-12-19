### 解题思路
每次得把上层取空

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            vector<int> temp;
            int len = qu.size();
            for(int i=0;i<len;i++){
                TreeNode* node = qu.front();
                qu.pop();
                temp.push_back(node->val);
                if(node->left != nullptr) qu.push(node->left);
                if(node->right != nullptr) qu.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```