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
    int res=INT_MAX;
    int pre=-888888;
    int getMinimumDifference(TreeNode* root) {
        if(root!=NULL){
            getMinimumDifference(root->left);
            int now=root->val;
            res=min(res,now-pre);
            pre=now;
            getMinimumDifference(root->right);
        }
        return res;
    }
};
```