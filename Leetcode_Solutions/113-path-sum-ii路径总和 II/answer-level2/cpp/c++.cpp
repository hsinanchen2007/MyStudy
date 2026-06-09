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
    void hasPathSum(TreeNode* root,vector<vector<int>>&res,vector<int>one,int sum)//此函数中，one不能使用引用传递，要保证每次递归返回时相应的不符合要求的元素也会清空，而不是保留!!!!!!!
    {
        if(root==NULL)
        {
            return ;
        }
        one.push_back(root->val);
        int temp=sum-root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            if(temp==0)
            {
                res.push_back(one);
                one.clear();
                return;
            }
            else
            {
                return;
            }
        }
        if(root->left)
        {
            hasPathSum(root->left,res,one,temp);
        }
        if(root->right)
        {
            hasPathSum(root->right,res,one,temp);
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>temp;
        hasPathSum(root,res,temp,sum);
        return res;
    }
};
```