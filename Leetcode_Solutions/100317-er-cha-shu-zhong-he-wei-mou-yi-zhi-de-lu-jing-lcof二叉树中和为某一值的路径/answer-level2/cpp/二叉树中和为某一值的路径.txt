### 解题思路
回溯算法 

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>temp;
        help(root,sum,res,temp);
        return res;
    }
    void help(TreeNode* root,int sum,vector<vector<int>>&res,vector<int>&temp){
        if(!root)   return ;
        
        sum -= root->val;
        temp.push_back(root->val);
        if(sum == 0 && !root->left && !root->right){
            res.push_back(temp);            //注意这里不能直接return
                                            //要先pop_back再return
        }
        
        if(root->left)  help(root->left,sum,res,temp);
        if(root->right) help(root->right,sum,res,temp);
        temp.pop_back();
        sum += root->val;
    }
};
```