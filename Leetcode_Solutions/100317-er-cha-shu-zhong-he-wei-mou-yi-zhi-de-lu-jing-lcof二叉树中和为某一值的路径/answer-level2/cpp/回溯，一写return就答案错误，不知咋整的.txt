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
        if(!root)return {};
        vector<int> path;
        vector<vector<int>> res;
        pathSum(root, res, path, sum, 0);
        return res;
    }
    void pathSum(TreeNode *x, vector<vector<int>> &res, vector<int> &path, int &totalSum, int currSum)
    {
        currSum += x->val;  //首先将当前节点值加上！！！
        path.push_back(x->val);  //然后将当前节点值push_back！！！
        bool isLeaf = (x->left==nullptr && x->right==nullptr);  //然后判断是否叶子节点
        if(isLeaf && (currSum==totalSum))
        {
            //既是叶子节点，也满足求和条件
            res.push_back(path);
        }
        if(x->left)
        {
            pathSum(x->left, res, path, totalSum, currSum);
        }       
        if(x->right)
        {
            pathSum(x->right, res, path, totalSum, currSum);
        }
        path.pop_back();  //记得撤回上一步操作，回溯
    }
};
```