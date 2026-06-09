### 解题思路
深度优先搜索

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
    map<int,vector<int>> hash;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root,0);
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        int n= 0;
        for(auto key:hash){
            n++;
            if(n%2 == 0){
                 reverse(key.second.begin(),key.second.end());
            }
            result.push_back(key.second);

        }
        return result;
    }
    void dfs(TreeNode * root,int deepth){
        if(root == NULL){
            return;
        }
        hash[deepth].push_back(root->val);
        dfs(root->left,deepth+1);
        dfs(root->right,deepth+1);
    }
};
```