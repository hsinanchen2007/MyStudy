### 解题思路
右子树存在时左子树必须有括号

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
    string tree2str(TreeNode* t) {
        if(t==NULL){
            return "";
        }
        if(t->right){
            return (to_string(t->val)+"("+tree2str(t->left)+")"+"("+tree2str(t->right)+")");
        }
        if(t->left){
            return (to_string(t->val)+"("+tree2str(t->left)+")");
        }
        if(!t->left&&!t->right){
            return to_string(t->val);
        }
        return "";
    }
};


```