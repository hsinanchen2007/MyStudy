### 解题思路
使用 Deque, 进行切换

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
        if(!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        int times = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> subres;
            for(int i = 0; i<n; ++i) {
                if((times & 0x1) == 1) {
                    TreeNode* temp = q.front();
                    q.pop_front();
                    subres.push_back(temp->val);
                    if(temp->right) q.push_back(temp->right);
                    if(temp->left) q.push_back(temp->left);
                }
                else{
                    TreeNode* temp = q.back();
                    q.pop_back();
                    subres.push_back(temp->val);
                    if(temp->left) q.push_front(temp->left);
                    if(temp->right) q.push_front(temp->right);
                }
             }
            res.push_back(subres);
            times++;
        }
        return res;
    }
};
```