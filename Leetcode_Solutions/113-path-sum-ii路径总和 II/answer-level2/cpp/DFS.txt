### 解题思路
深度优先搜索。只不过需要将结果找到的结果保留下来。具体做法：
设置一个临时的数组保存已经历遍到的元素。在递归调用的时候，每次先将当前根节点的元素存入数组，然后将sum的值减去当前的元素值。一直历遍到叶节点，如果此时sum减去当前的元素值等于0，那么说明这个路径的和为sum。这是就找到了一条路径，并将其存入结果中。

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
        vector<vector<int>> res;
        vector<int> temp;

        if(!root) return res;
        dfs(root, res, temp, sum);
        return res;
    }

    //注意，下面的res应该设为引用，但是temp不可以设为引用
    void dfs(TreeNode* root,vector<vector<int>> &res, vector<int> temp, int sum)
    {
        temp.push_back(root->val);
        if(!root->left && !root->right && 0 == sum - root->val) 
            res.push_back(temp); //这里自己一开始写成了 0==sum ,导致输出结果为空或者错
        if(root->left) 
            dfs(root->left, res,  temp, sum - root->val);
        if(root->right) 
            dfs(root->right, res, temp, sum - root->val);
    }
};
```