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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(!root) return result;
        if(root->left==nullptr && root->right==nullptr && root->val==sum){
            vector<int> res;
            res.push_back(sum);
            result.push_back(res);
            return result;
        }
        vector<int> ans;
        ans.push_back(root->val);
        find(root->left,sum,root->val,result,ans);
        find(root->right,sum,root->val,result,ans);
        return result;
    }
    void find(TreeNode* root,int sum,int res,vector<vector<int>> &result,vector<int>& ans){
        if(!root) return;
        ans.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(res+root->val==sum)
                result.push_back(ans);
            ans.pop_back();
        }
        else{
            res+=root->val;
            find(root->left,sum,res,result,ans);
            find(root->right,sum,res,result,ans);
            res-=root->val;
            ans.pop_back();
        }
    }
};
```