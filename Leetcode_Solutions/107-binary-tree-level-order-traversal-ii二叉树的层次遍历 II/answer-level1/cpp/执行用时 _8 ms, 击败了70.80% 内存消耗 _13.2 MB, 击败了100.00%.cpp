### 解题思路
queue+ 反转

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        TreeNode *p = root;
        if(root) q.push(p);
        int level = 0;
        
        while(!q.empty()){
                int n = q.size();
                res.push_back(vector<int>());
                while(n!=0){
                    p = q.front();
                    res[level].push_back(p->val);
                    if(p->left != NULL)  q.push(p->left);
                    if(p->right != NULL)  q.push(p->right);
                    q.pop();
                    n--;
                }   
                level++;
            }
        reverse(res.begin(),res.end());
        return res;
    }
    
};
```