### 解题思路
vector<int> path 存储一条根到叶节点的路径，vector<vector<int>> pathall 存储所有满足条件的路径
如果是空结点，则不存在路径，返回{}；
遇到非空结点，sum -= root->val, root->val放入路径存储数组path中；
   如果是叶节点（即左右子树均为空），且sum==0，则该路径是所求路径，放入pathall中收集
   如果不是空结点也不是叶节点，左子树与右子树递归调用；

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
        if(!root) return {};
        vector<int> path;
        vector<vector<int>> pathall;
        path_sum_help(root, sum, path, pathall);
        return pathall;
    }
    void path_sum_help(TreeNode* root, int sum, vector<int>& path,
                       vector<vector<int>>& pathall)
    {
        if(!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if(!(root->left) && !(root->right))
        {
            if(sum == 0)
                pathall.push_back(path);
            return;
        }

        vector<int> left_path = path;
        vector<int> right_path = path;
        path_sum_help(root->left, sum, left_path, pathall);
        path_sum_help(root->right, sum, right_path, pathall); 
    }
};
```