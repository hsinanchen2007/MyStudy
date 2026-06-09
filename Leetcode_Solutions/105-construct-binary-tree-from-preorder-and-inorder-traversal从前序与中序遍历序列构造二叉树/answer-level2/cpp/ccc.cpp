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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i = 0;i < inorder.size();++i){
            m[inorder[i]] = i; 
        }
        return helper(m,preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* helper(unordered_map<int,int>& m,vector<int>& preorder,vector<int>& inorder,
                    int preleft,int preright,int inleft,int inright)
    {
        if(preleft > preright || inleft > inright)return NULL;
        auto root = new TreeNode(preorder[preleft]);
        auto num = m[preorder[preleft]]-inleft;
        root->left = helper(m,preorder,inorder,preleft+1,preleft+num,inleft,inleft+num-1); 
        root->right = helper(m,preorder,inorder,preleft+num+1,preright,inleft+num+1,inright);
        return root;
    }
};
```