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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* new_node = NULL;
        if(t1!=NULL||t2!=NULL){
        new_node=new TreeNode((t1!=NULL ? t1->val : 0) + (t2!=NULL ? t2->val : 0));
        new_node->left = mergeTrees((t1!=NULL ? t1->left : NULL),(t2!=NULL ? t2->left : NULL));
        new_node->right = mergeTrees((t1!=NULL ? t1->right : NULL),(t2!=NULL ? t2->right : NULL));
        }
        return new_node;
    }
};
```