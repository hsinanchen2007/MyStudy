### 解题思路
引入队列

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;//树为空的情况
        queue<TreeNode*> q;
        TreeNode *p;
        q.push(root);
        while(!q.empty()){
            p = q.front();
            res.push_back(p->val);
            q.pop();
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
        return res;

    }
};
```