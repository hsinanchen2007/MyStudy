### 解题思路
1. 用临时数组记录当前路径上所有节点的值(递归实现)
2. 当访问记录到叶子节点，计算路径总和。记录符合要求的路径

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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int sum, vector<int> temp){
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int s = 0;
            for(auto n: temp) s += n;
            if(s == sum) ans.push_back(temp);
        }
        if(root->left) dfs(root->left, sum, temp);
        if(root->right) dfs(root->right, sum, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return ans;
        dfs(root, sum, {});
        return ans; 
    }
};
```