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
    vector<int> elm;
    vector<vector<int>> arr;
    void help(TreeNode* root,int sum)
    {
        if(root==NULL)
        {
            elm.push_back(0);
            return;
        }
        else if(sum==root->val&&root->left==NULL&&root->right==NULL)
        {
            elm.push_back(root->val);
            arr.push_back(elm);
            return;
        }
        else if(root->left!=NULL||root->right!=NULL)
        {
            elm.push_back(root->val);
            help(root->left,sum-root->val);
            elm.erase(elm.begin()+elm.size()-1);
            help(root->right,sum-root->val);
            elm.erase(elm.begin()+elm.size()-1);
            
        }
        else {
            elm.push_back(0);
            return;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        help(root,sum);
        return arr;
    }
};
```