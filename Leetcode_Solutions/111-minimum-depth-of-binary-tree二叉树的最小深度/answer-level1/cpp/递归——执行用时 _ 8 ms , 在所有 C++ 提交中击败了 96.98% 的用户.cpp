### 解题思路
left或者right中有一个是NULL的时候，需要取max而非min

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
    	if(!root) return 0;
    	return (!root->left || !root->right)? max(minDepth(root->left),minDepth(root->right)) + 1:
    			min(minDepth(root->left),minDepth(root->right))+1;
    }
};
```