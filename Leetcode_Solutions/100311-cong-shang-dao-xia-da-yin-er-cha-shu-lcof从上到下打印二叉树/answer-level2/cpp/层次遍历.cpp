### 解题思路
做一下树的层次遍历就好了，应该算简单题吧。

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
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            if(p!=NULL)
            {
                res.push_back(p->val);
            q.push(p->left);
            q.push(p->right);
            }
        }
        return res;
    }
};
```