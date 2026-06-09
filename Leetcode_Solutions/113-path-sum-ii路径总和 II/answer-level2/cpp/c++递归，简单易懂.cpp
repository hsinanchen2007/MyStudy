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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> tmp;
        test(root, sum, tmp);
        return res;
    }

    void test(TreeNode* root, int sum, vector<int> &tmp)//这里记得传引用。。。
    {
        if(!root) return ;
        tmp.push_back(root -> val);
        if(root -> val == sum && !root -> left && !root -> right)
        {
            res.push_back(tmp);
        }
        else
        {
            test(root -> left, sum - root -> val, tmp);
            test(root -> right, sum - root -> val, tmp);
        }
        tmp.pop_back();
    }
};

```