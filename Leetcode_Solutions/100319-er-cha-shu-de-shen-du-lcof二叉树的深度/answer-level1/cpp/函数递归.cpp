### 解题思路
调用函数自身判断左子树和右子树的最大深度，然后+1
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
    int maxDepth(TreeNode* root) {
        int result;
        if(root==nullptr){
            return 0;
        }else{
            result=1;
        }
        int tmp=max(maxDepth(root->left),maxDepth(root->right));
        result+=tmp;
        return result;
    }
};
```