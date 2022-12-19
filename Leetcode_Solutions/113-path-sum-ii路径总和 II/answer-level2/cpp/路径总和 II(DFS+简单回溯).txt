### 解题思路

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
class Solution 
{
public:
    vector<vector<int>> res;
    vector<int> way;

    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(!root) return res;
        DFS(root,0,sum);
        return res;
    }

    void DFS(TreeNode* root,int _sum,int sum)
    {
        way.push_back(root->val);

        _sum+=root->val;
        if(_sum==sum && !root->left && !root->right) 
            res.push_back(way);

        if(root->left) DFS(root->left,_sum,sum);
        if(root->right) DFS(root->right,_sum,sum);

        way.pop_back();
    }
};
```
![image.png](https://pic.leetcode-cn.com/e69b46c9d3d978fad1710f41e5e4732a5e04d1ce0d9beb987f591385219f14eb-image.png)
