### 解题思路
先遍历第一遍树，求得树的深度，以此构造二维vector，然后第二次遍历树，将结点装入vector中相应的位置，一定要用(l+r)/2来求解坐标，刚开始还找了半天规律，搞的我头晕，后来才发现是(l+r)/2 太菜了我

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
    int m=0;
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if(root==NULL)
            return res;
        help(root,1);
        vector<string> tmp(pow(2,m)-1);
        res.resize(m,tmp);
        //cout<<m<<endl;
        
        help1(root,0,0,tmp.size(),res);
        return res;
    }
    void help(TreeNode* root, int depth)
    {
        if(root==NULL)
            return;
        help(root->left,depth+1);
        help(root->right,depth+1);
        m=max(m,depth);
    }
    void help1(TreeNode* root,int i,int l,int r,vector<vector<string>>& res)
    {
        if(root==NULL)
            return;
        res[i][(l+r)/2]=to_string(root->val);
        help1(root->left,i+1,l,(l+r)/2-1,res);
        help1(root->right,i+1,(l+r)/2+1,r,res);
    }

};
```