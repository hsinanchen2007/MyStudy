### 解题思路
获取树上的所有值，然后将所有值依次两两相减，找出最小值。

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
        
        vector<int> v;
        
        f(v,root);
        
        int smaller=INT_MAX;
        
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                smaller=min(smaller,abs(v[i]-v[j]));
            }
        }
        
        return smaller;

    }
    
    void f(vector<int>& v,TreeNode* root)
    {
        v.push_back(root->val);
        
        if(root->left!=NULL)
        {
            f(v,root->left);
        }
        if(root->right!=NULL)
        {
            f(v,root->right);
        }
    }
};
```