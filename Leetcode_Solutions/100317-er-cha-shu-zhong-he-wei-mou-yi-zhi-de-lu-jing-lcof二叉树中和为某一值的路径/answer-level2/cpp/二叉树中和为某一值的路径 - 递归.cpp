### 解题思路
1. 本题同[113.路径总和](https://leetcode-cn.com/problems/path-sum-ii/)
2. [题解](https://leetcode-cn.com/problems/path-sum-ii/solution/di-gui-ji-suan-lu-jing-zong-he-by-jarvis1890/)

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return ans;
        dfs(root, sum, {});
        return ans;
    }
    
    void dfs(TreeNode* root, int sum, vector<int> tmp){
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int s = 0;
            for(int n : tmp) s+= n;
            if(s == sum) ans.push_back(tmp);
        }
        if(root->left) dfs(root->left, sum, tmp);
        if(root->right) dfs(root->right, sum, tmp);
    }
};
```