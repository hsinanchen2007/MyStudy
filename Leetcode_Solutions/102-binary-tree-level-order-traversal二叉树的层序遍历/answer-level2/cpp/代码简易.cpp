### 解题思路
见注释

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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode *root){
        solve(root,0);
        return res;
    }
    void solve(TreeNode *root,int deep){
        if(!root) return;
        //如果此时的深度已经大于数组大小，则增加一层
        if(deep >=res.size()) //这里可以取等于号，因为ans.size还不在下标里面
            res.push_back(vector<int>{});
        res[deep].push_back(root->val);
        solve(root->left,deep+1);
        solve(root->right,deep+1);
            
    }
}; 
```