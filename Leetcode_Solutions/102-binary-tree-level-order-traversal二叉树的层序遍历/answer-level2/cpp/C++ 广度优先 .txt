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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL)
        {
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        int curCount = 1;       //当前这一层有几个结点
        while(!q.empty())
        {
            vector<int>temp;
            int nextCount = 0;      //下一层有几个结点
            for(int i = 0; i < curCount; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left != NULL) 
                {
                    q.push(cur->left);
                    nextCount++;
                }
                if(cur->right != NULL) 
                { 
                    q.push(cur->right); 
                    nextCount++;
                }
            }
            res.push_back(temp);
            curCount = nextCount;
        }
        return res;
    }
};
```