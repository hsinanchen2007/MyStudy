### 解题思路
BFS,push_back每一层最后一个节点

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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        return vector<int>(0);
        queue<TreeNode*> q;
        vector<int> ans;
        TreeNode* last=root;
        TreeNode* tail=NULL;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left!=NULL)
            {
                q.push(cur->left);
                if(cur->right==NULL)
                tail=cur->left;
                else
                {
                    q.push(cur->right);
                    tail=cur->right;
                }
            }
            else
            {
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                    tail=cur->right;
                }
            }
            if(cur==last)
            {
                ans.push_back(cur->val);
                last=tail;
            }
        }
        return ans;
    }
};
```