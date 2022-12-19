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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
        return true;
    if(p==NULL||q==NULL)
        return false;
    
    bool result = true;
    if(p->val!=q->val)
        return false;
    result = result&&isSameTree(p->left, q->left);
    result = result&&isSameTree(p->right, q->right);
    return result;
    }
};
```