### 解题思路
从当前节点判断它是奇数还是偶数，再取他的孙子节点就行。

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
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        if(root->val%2==0)
        {
            if(root->left)
            {
                if(root->left->left)sum+=root->left->left->val;
                if(root->left->right)sum+=root->left->right->val;
            }
            if(root->right)
            {
                if(root->right->left)sum+=root->right->left->val;
                if(root->right->right)sum+=root->right->right->val;
            }
        }
        return sum+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};
```