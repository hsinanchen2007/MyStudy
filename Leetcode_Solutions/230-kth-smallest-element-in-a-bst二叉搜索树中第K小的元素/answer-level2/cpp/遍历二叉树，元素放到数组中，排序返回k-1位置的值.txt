### 解题思路
此处撰写解题思路

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *temp=que.front();
            que.pop();
            ans.push_back(temp->val);
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
        
    }
};
```