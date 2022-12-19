

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
        int result = 0;
        Treeheight(root,result);
        if(!result)
            return true;
        else 
            return false;
    }
    int Treeheight(TreeNode *root,int &result)
    {
        if(root == NULL)
            return 0;
        else
        {
            int LD = Treeheight(root->left,result);
            int RD = Treeheight(root->right,result);
            if(abs(LD-RD) >1)
                result = 1;
            return (LD>RD?LD:RD)+1;
        }
    }
};
```