### 解题思路
因为是二叉搜索树，中序遍历获取递增数组，对比数组内所有相邻数的差，取最小值。

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
    int minDiffInBST(TreeNode* root) {
        
        vector<int> v;
        
        f(root,v);
        
        int num=INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            int temp=v[i+1]-v[i];
            num=min(num,temp);
        }
        
        return num;

    }
    
    void f(TreeNode* root,vector<int>& v)
    {
        if(root==NULL)
        {
            return;
        }
        
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
    }
};
```