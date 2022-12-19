### 解题思路
中序遍历得到有序数组，求有序数组中的相邻两个元素的差值的最小值即可

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
    int getMinimumDifference(TreeNode* root) {
        vector<int>res;
        inorder(root,res);

        int Min=65535;

        for(int i = 0;i < res.size()-1;i++)
        {
            Min = min(Min,res[i+1]-res[i]);
        }
        return Min;
    }
    TreeNode *inorder(TreeNode *root,vector<int>&res)
    {
        if(root==NULL)return NULL;
        inorder(root->left,res);

        res.push_back(root->val);

        inorder(root->right,res);

        return root;
    }

};
```