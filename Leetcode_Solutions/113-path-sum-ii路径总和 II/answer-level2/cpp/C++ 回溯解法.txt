### 解题思路
首先想到应用回溯进行处理，然后处理边界情况如何返回即可

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
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        help(root,sum);
        return res;
    }
    void help(TreeNode* root, int sum)
    {
        if(!root)
            return ;
        if(sum==root->val&&root->left==NULL&&root->right==NULL)
        {
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        tmp.push_back(root->val);
        help(root->left,sum-(root->val));
        tmp.pop_back();
        tmp.push_back(root->val);
        help(root->right,sum-(root->val));
        tmp.pop_back();
    }
};
```