### 解题思路
用队列存储结点
定义一个长度保证每次弹出的是同一层结点
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
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int len = q.size();
            vector<int>level;
            for(int i = 0;  i < len; i++){
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(level);
        }
        return res;
        
    }
};
```