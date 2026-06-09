### 解题思路
我这个复杂度是不是也是O(N)，为什么这么耗时呢
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(!root->left&&!root->right) return 1;//左右子树都为空
        if(!root->left||!root->right) {//一个为空
            int left_h=minDepth(root->left);
            int right_h=minDepth(root->right);
            return max(left_h,right_h)+1;
        }
        else{//
            int left_h=minDepth(root->left);
            int right_h=minDepth(root->right);
            return min(left_h,right_h)+1;
        }
    }
};
```