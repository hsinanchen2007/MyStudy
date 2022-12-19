### 解题思路
简单的DFS +回溯
返回条件
1）空指针要返回
2）如果是叶子节点，且和为目标值，要返回

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
    vector<vector<int>> result;
    void dfs(TreeNode* root, int sum,vector<int> &path,int target){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            if(root->val+sum == target){
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();

            }
            return;
        }

        path.push_back(root->val);
        dfs(root->left, root->val + sum, path, target);
        path.pop_back();

        path.push_back(root->val);
        dfs(root->right, root->val + sum, path, target);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        vector<int> path;
        dfs(root, 0,path,sum);

        return result;
    }
};
```