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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        heigh(root, res);
        return res;
    }

    int heigh(TreeNode* root,bool &res)
    {
        if(!root)  return 0;
        int left = heigh(root->left, res) + 1;
        int right = heigh(root->right, res) + 1;
        if(abs(left-right) > 1)
        {
            res=false;
        }
        return max(left,right);   
    }
};
//递归过程中每次都比较左右子树的长度。
```