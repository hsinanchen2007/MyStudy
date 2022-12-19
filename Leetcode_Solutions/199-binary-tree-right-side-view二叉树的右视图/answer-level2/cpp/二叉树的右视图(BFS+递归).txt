### 解题思路

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
class Solution 
{
public:
    queue<TreeNode*> q;
    vector<TreeNode*> TreeLevel;
    vector<int> res;

    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root) return res;
        q.push(root);
        BFS(0);
        return res;
    }

    void BFS(int LevelLen)
    {
        while(!q.empty())
        {
            TreeNode* pre=q.front();
            q.pop();

            if(q.empty()) res.push_back(pre->val);
            if(pre->left) TreeLevel.push_back(pre->left);
            if(pre->right) TreeLevel.push_back(pre->right);
        }

        if(TreeLevel.size()>LevelLen) 
        {
            for(int i=LevelLen;i<TreeLevel.size();i++) 
                q.push(TreeLevel[i]);

            BFS(TreeLevel.size());
        }
    }
};
```