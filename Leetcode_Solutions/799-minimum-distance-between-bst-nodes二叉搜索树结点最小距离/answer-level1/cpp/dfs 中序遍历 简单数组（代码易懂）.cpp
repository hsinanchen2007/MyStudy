### 解题思路
中序遍历树，用数组记录，之后算出每两个节点的差值，遍历找出最小值。

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
    void dfs(TreeNode* root,vector<int>&res){
        if(root==NULL){
            return;
        }
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }

    int minDiffInBST(TreeNode* root) {
         vector<int>res;
         vector<int>num;
         dfs(root,res);
         int Min=INT_MAX;
         for(int i=1;i<res.size();i++){
             num.push_back(res[i]-res[i-1]);
         }
         for(int i=0;i<num.size();i++){
             Min=min(num[i],Min);
         }
         return Min;
    }
};
```