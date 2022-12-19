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
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> res;
        inorder(root,res);
        return BuildAVL(res,0,res.size()-1);
    }

    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root)
        {
            if(root->left) inorder(root->left,res);
            res.push_back(root->val);
            if(root->right) inorder(root->right,res);
        }
    }

    TreeNode* BuildAVL(vector<int>& res,int low,int high)
    {
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(res[mid]);

        if(mid-1>=low) root->left=BuildAVL(res,low,mid-1);
        if(mid+1<=high) root->right=BuildAVL(res,mid+1,high); 

        return root;   
    }
};
```