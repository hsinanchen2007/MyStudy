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
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, 0, sum);
        return result;
    }

     void dfs(TreeNode* rt, int curr, int sum){
         if (rt == NULL) {
             return;
         }

         path.push_back(rt->val);
         curr += rt->val;
         if (rt->left == NULL && rt->right == NULL) {
             if (curr == sum) {
                result.push_back(path);
             }
            path.pop_back();
            curr -= rt->val;
            return;
         }

         dfs(rt->left, curr, sum);
         dfs(rt->right, curr, sum);
         path.pop_back();
         curr -= rt->val;
    } 
};
```