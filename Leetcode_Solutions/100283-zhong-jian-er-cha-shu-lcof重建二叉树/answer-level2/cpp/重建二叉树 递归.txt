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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size()==0 || inorder.size()==0)
        {
            return NULL;
        }  
        int start_pre=0, end_pre=preorder.size()-1;
        int start_in=0, end_in=inorder.size()-1;  
        return build(start_pre, end_pre, start_in, end_in, preorder, inorder);
    }
    TreeNode* build(int start_pre, int end_pre, int start_in, int end_in, 
                    vector<int>& preorder, vector<int>& inorder)
                {
                    if(start_pre > end_pre)
                    {
                        return NULL;
                    }
                    TreeNode* root= new TreeNode(preorder[start_pre]);
                    int len=0;
                    while(inorder[start_in+len] != preorder[start_pre])
                    {
                        ++len;
                    }
                    root->left=build(start_pre+1, start_pre+len, 
                                    start_in, start_in+len-1, preorder, inorder);
                    root->right=build(start_pre+len+1, end_pre, 
                                    start_in+len+1, end_in, preorder, inorder);
                    return root;
                }
};


```