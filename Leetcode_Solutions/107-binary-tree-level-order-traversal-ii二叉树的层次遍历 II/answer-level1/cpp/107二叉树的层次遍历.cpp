### 解题思路
按层深搜
按层存储
最后反转
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
    vector<vector<int>> vt;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return vt;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> tmp;
            vector<int> now;
            while(!q.empty()){
                TreeNode* pre=q.front();
                q.pop();
                now.push_back(pre->val);
                if(pre->left) 
                    tmp.push(pre->left);
                if(pre->right)
                    tmp.push(pre->right);
            }
            q=tmp;
            vt.push_back(now);
        }
       reverse(vt.begin(),vt.end());

        return vt;
    }
};
```