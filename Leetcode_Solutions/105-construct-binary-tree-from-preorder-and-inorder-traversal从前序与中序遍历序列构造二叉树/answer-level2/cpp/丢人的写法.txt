### 解题思路

![image.png](https://pic.leetcode-cn.com/74bd4bebe5bfdc0c20558b7cbb68ab348782e653f38f2e5cecef9f8855a7697e-image.png)

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
        int len = inorder.size();
        if(len == 0) return NULL;
        TreeNode * root = new TreeNode(preorder[0]);
        vector<int> left_pre,left_in,right_pre,right_in;
        int pos=0;
        for(int i=0;i<len;++i)
        {
            if(preorder[0]==inorder[i])
            {
                pos =i;
                break;
            }
        }
        for(int i = 0; i<pos;++i)
        {
            left_in.push_back(inorder[i]);
            left_pre.push_back(preorder[i+1]);
        }
        for(int i = pos+1; i<len;++i)
        {
            right_pre.push_back(preorder[i]);
            right_in.push_back(inorder[i]);
        }

        root->left = buildTree(left_pre,left_in);
        root->right = buildTree(right_pre,right_in);
        return root;
    }
};
```