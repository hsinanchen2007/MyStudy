### 解题思路
辅助队列FIFO

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
        vector<vector<int>>res;
        if(!root) return res;
        queue<TreeNode*>s;
        s.push(root);
        while(s.size()){
            vector<int>temp;
            int len = s.size();
            for(int i = 0;i < len;i++){
                TreeNode* node = s.front();
                s.pop();
                if(node->left) s.push(node->left);
                if(node->right) s.push(node->right);
                temp.push_back(node->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```