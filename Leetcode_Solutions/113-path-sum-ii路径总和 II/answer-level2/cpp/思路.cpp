### 解题思路
此处撰写解题思路dfs,其实难度不到，主要需要理清，什么时候push和pop

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

    void dfs(TreeNode* root, int sum, vector<int>& tmp){
      if(root == NULL)  
        return;

      if(root->left == NULL && root->right == NULL){
        if(sum == root->val){
          tmp.push_back(root->val);
          res.push_back(tmp);
          tmp.pop_back();
        }
        return;
      }

      tmp.push_back(root->val);
      dfs(root->left, sum - root->val, tmp);
      dfs(root->right, sum - root->val, tmp);
      tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      if(root == NULL) return res;

      vector<int> tmp;
      dfs(root, sum, tmp);
      return res;
    }
};
```